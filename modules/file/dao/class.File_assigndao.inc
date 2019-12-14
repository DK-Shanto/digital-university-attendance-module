<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.file.inc';
include_once UTILITY.'class.util.inc';

Class File_assignDAO{

	private $_DB;
	private $_File_assign;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_File_assign = new File_assign();

	}

	// get all the File_assigns from the database using the database query
	public function getAllFile_assigns(){

		$File_assignList = array();

		$this->_DB->doQuery("SELECT * FROM fms_file_assign");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_File_assign = new File_assign();


			$this->_File_assign->setID( $row['ID']);
			$this->_File_assign->setFile( $row['FileID']);
			$this->_File_assign->setFileComment( $row['FileComment']);
			$this->_File_assign->setIsApproved( $row['IsApproved']);
			$this->_File_assign->setIsRejected( $row['IsRejected']);

			$this->_File_assign->setPreviousUser( $row['PreviousUserID']);
			$this->_File_assign->setCurrentUser( $row['CurrentUserID']);
			$this->_File_assign->setIsPending( $row['IsPending']);
			$this->_File_assign->setHasSeen( $row['HasSeen']);
			$this->_File_assign->setCreationDate( $row['CreationDate']);
			$this->_File_assign->setApproveDate( $row['ApproveDate']);
			$this->_File_assign->setAssignDate( $row['AssignDate']);


		    $File_assignList[]=$this->_File_assign;
   
		}

		//print_r($File_assignList);

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($File_assignList);

		return $Result;
	}



	public function createFile_assign_and_append($File_assign)
    {
        $ID = $File_assign->getFile()->getID();

        $SQL1 = "SELECT * 
                    FROM `fms_fileassign` 
                    WHERE fms_fileassign.ID = '$ID'
                    ORDER BY fms_fileassign.timestamp DESC LIMIT 1";

        //

        $FileComment=$File_assign->getFileComment();
        $FileSender = $File_assign->getSender();
        $FileReceiver = $File_assign->getReceiver();
        $FileLink = $File_assign->getLinks();





        $SQL = "INSERT INTO fms_fileassign(ID, sender, receiver, disciplineID, comment, timestamp, links) VALUES('$ID', '$FileSender', '$FileReceiver', '', '$FileComment', now(), '$FileLink')";

        //echo $SQL;

        $SQL = $this->_DB->doQuery($SQL);

        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;

    }


    public function getFileAssignToBeAppended($File)
    {
        $File_assignList = array();
        $thisUser = $globalUser = $_SESSION['globalUser']->getID();

        $fileid = $File->getID();




        $this->_DB->doQuery("SELECT * 
                FROM `fms_fileassign` 
                WHERE fms_fileassign.ID = '$fileid'
                ORDER BY fms_fileassign.timestamp DESC LIMIT 1");



        $rows = $this->_DB->getAllRows();

        for($i = 0; $i < sizeof($rows); $i++) {
            $row = $rows[$i];
            $this->_File_assign = new File_assign();

            $_File = new File();


            $this->_File_assign->setFile($_File);
            $this->_File_assign->setFileComment( $row['comment']);
            $this->_File_assign->setSender($row['sender']);
            $this->_File_assign->setReceiver($row['receiver']);
            $this->_File_assign->setTimestamp($row['timestamp']);
            $this->_File_assign->setLinks($row["links"]);



            $File_assignList[]=$this->_File_assign;

        }

        //print_r($File_assignList);

        //todo: LOG util with level of log


        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($File_assignList);

        return $Result;
    }


	public function getFileHistory($File)
    {
        $fileid = $File->getID();
        $File_assignList = array();
        $this->_DB->doQuery("SELECT * FROM fms_fileassign WHERE fms_fileassign.ID = '$fileid' ORDER BY fms_fileassign.timestamp");

        $rows = $this->_DB->getAllRows();
        for($i = 0; $i < sizeof($rows); $i++) {
            $row = $rows[$i];
            $this->_File_assign = new File_assign();

            $_File = new File();
            $_File->setID($row['ID']);


            $this->_File_assign->setFile($_File);
            $this->_File_assign->setFileComment( $row['comment']);
            $this->_File_assign->setSender($row['sender']);
            $this->_File_assign->setReceiver($row['receiver']);
            $this->_File_assign->setTimestamp($row['timestamp']);
            $this->_File_assign->setLinks($row['links']);
            //$this->_File_assign->setDiscipline($row['Name']);


            $File_assignList[]=$this->_File_assign;

        }

        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($File_assignList);

        return $Result;

    }


    public function getAllReceivedFile_assigns()
    {
        $File_assignList = array();
        $thisUser = $globalUser = $_SESSION['globalUser']->getID();

        $this->_DB->doQuery("SELECT fms_fileassign.ID,fms_fileassign.sender,fms_fileassign.receiver,fms_fileassign.comment,fms_fileassign.timestamp,fms_file.Link,fms_file.CreatorID,fms_file.CurrentUser,T.DispName

FROM fms_fileassign,fms_file,
						(SELECT ums_user.ID AS FileReceiver,ums_discipline.Name AS DispName
							FROM ums_discipline,ums_user
							WHERE ums_discipline.ID = ums_user.DisciplineID) AS T

WHERE fms_fileassign.ID = fms_file.ID AND fms_fileassign.receiver = T.FileReceiver AND fms_file.CurrentUser = '$thisUser' AND CurrentUser = receiver");



        $rows = $this->_DB->getAllRows();

        for($i = 0; $i < sizeof($rows); $i++) {
            $row = $rows[$i];
            $this->_File_assign = new File_assign();

            $_File = new File();
            $_File->setCurrentUser($row['CurrentUser']);
            $_File->setLink($row['Link']);
            $_File->setID($row['ID']);
            $_File->setCreator($row['CreatorID']);




            $this->_File_assign->setFile($_File);
            $this->_File_assign->setFileComment( $row['comment']);
            $this->_File_assign->setSender($row['sender']);
            $this->_File_assign->setReceiver($row['receiver']);
            $this->_File_assign->setTimestamp($row['timestamp']);
            //$this->_File_assign->setDiscipline($row['Name']);
            $this->_File_assign->setDiscipline($row['DispName']);







            $File_assignList[]=$this->_File_assign;

        }

        //print_r($File_assignList);

        //todo: LOG util with level of log


        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($File_assignList);

        return $Result;
    }


    // get all the File_assigns from the database using the database query
    public function getAllFile_assigns2(){

        $File_assignList = array();
        $thisUser = $globalUser = $_SESSION['globalUser']->getID();

        $this->_DB->doQuery("SELECT fms_fileassign.ID,fms_fileassign.sender,fms_fileassign.receiver,fms_fileassign.comment,fms_fileassign.timestamp,fms_file.Link,fms_file.CreatorID,fms_file.CurrentUser,T.DispName FROM fms_fileassign,fms_file, (SELECT ums_user.ID AS FileReceiver,ums_discipline.Name AS DispName FROM ums_discipline,ums_user WHERE ums_discipline.ID = ums_user.DisciplineID) AS T WHERE fms_fileassign.ID = fms_file.ID AND fms_fileassign.receiver = T.FileReceiver AND fms_fileassign.sender = '$thisUser'
");



        $rows = $this->_DB->getAllRows();

        for($i = 0; $i < sizeof($rows); $i++) {
            $row = $rows[$i];
            $this->_File_assign = new File_assign();

            $_File = new File();
            $_File->setCurrentUser($row['CurrentUser']);
            $_File->setLink($row['Link']);
            $_File->setID($row['ID']);
            $_File->setCreator($row['CreatorID']);




            $this->_File_assign->setFile($_File);
            $this->_File_assign->setFileComment( $row['comment']);
            $this->_File_assign->setSender($row['sender']);
            $this->_File_assign->setReceiver($row['receiver']);
            $this->_File_assign->setTimestamp($row['timestamp']);
            //$this->_File_assign->setDiscipline($row['Name']);
            $this->_File_assign->setDiscipline($row['DispName']);







            $File_assignList[]=$this->_File_assign;

        }

        //print_r($File_assignList);

        //todo: LOG util with level of log


        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($File_assignList);

        return $Result;
    }

	//create File_assign funtion with the File_assign object
	public function createFile_assign($File_assign){

		$ID = $File_assign->getID();
		$FileID=$File_assign->getFile();
		$FileComment=$File_assign->getFileComment();
		$IsApproved=$File_assign->getIsApproved();
		$IsRejected=$File_assign->getIsRejected();
		$CurrentUserID=$File_assign->getCurrentUser();
		$PreviousUserID=$File_assign->getPreviousUser();
		$IsPending=$File_assign->getIsPending();
		$HasSeen=$File_assign->getHasSeen();
		$CreationDate=$File_assign->getCreationDate();
		$ApproveDate = $File_assign->getApproveDate();
		$AssignDate=$File_assign->getAssignDate();




		$SQL = "INSERT INTO fms_file_assign(ID, FileID, FileComment, IsApproved, IsRejected, PreviousUserID, CurrentUserID, IsPending, HasSeen, CreationDate, ApproveDate, AssignDate) VALUES('$ID','$FileID','$FileComment', '$IsApproved', '$IsRejected', '$PreviousUserID', '$CurrentUserID', '$IsPending', '$HasSeen', '$CreationDate','$ApproveDate','$AssignDate')";

		echo $SQL;

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}



	//Another CreateFileAssign
    public function createFile_assign2($File_assign){

        $ID = $File_assign->getFile()->getID();
        $FileComment=$File_assign->getFileComment();
        $FileSender = $File_assign->getSender();
        $FileReceiver = $File_assign->getReceiver();
        $FileLink = $File_assign->getLinks();





        $SQL = "INSERT INTO fms_fileassign(ID, sender, receiver, disciplineID, comment, timestamp, links) VALUES('$ID', '$FileSender', '$FileReceiver', '', '$FileComment', now(), '$FileLink')";

        //echo $SQL;

        $SQL = $this->_DB->doQuery($SQL);

        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }



	//read an File_assign object based on its id form File_assign object
	public function readFile_assign($File_assign){
		
		
		$SQL = "SELECT * FROM fms_file_assign WHERE ID='".$File_assign->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this File_assign from the database
		$row = $this->_DB->getTopRow();

		$this->_File_assign = new File_assign();

		//preparing the File_assign object
	    $this->_File_assign->setID ( $row['ID']);
		$this->_File_assign->setFile( $row['FileID']);
		$this->_File_assign->setFileComment( $row['FileComment']);
		$this->_File_assign->setIsApproved( $row['IsApproved']);
		$this->_File_assign->setIsRejected( $row['IsRejected']);

		$this->_File_assign->setPreviousUser( $row['PreviousUserID']);
		$this->_File_assign->setCurrentUser( $row['CurrentUserID']);
		$this->_File_assign->setIsPending( $row['IsPending']);
		$this->_File_assign->setHasSeen( $row['HasSeen']);
		$this->_File_assign->setCreationDate( $row['CreationDate']);
		$this->_File_assign->setApproveDate( $row['ApproveDate']);
		$this->_File_assign->setAssignDate( $row['AssignDate']);
		




	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_File_assign);

		return $Result;
	}

	public function searchFile_assign($CurrentUser){

		$File_assignList = array();

		
		//echo "SELECT * FROM fms_file_assign WHERE CurrentUserID = $CurrentUser and IsPending = true";		

		$this->_DB->doQuery("SELECT * FROM fms_file_assign WHERE CurrentUserID = '".$CurrentUser."'");
		//and IsPending = true");

		//WHERE CurrentUserID = $CurrentUser and IsPending = 1

		$rows = $this->_DB->getAllRows();

		echo sizeof($rows);

		//

		//reading the top row for this File_assign from the database

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];

			$this->_File_assign = new File_assign();


			$this->_File_assign->setID( $row['ID']);
			$this->_File_assign->setFile( $row['FileID']);
			$this->_File_assign->setFileComment( $row['FileComment']);
			$this->_File_assign->setIsApproved( $row['IsApproved']);
			$this->_File_assign->setIsRejected( $row['IsRejected']);

			$this->_File_assign->setPreviousUser( $row['PreviousUserID']);
			$this->_File_assign->setCurrentUser( $row['CurrentUserID']);
			$this->_File_assign->setIsPending( $row['IsPending']);
			$this->_File_assign->setHasSeen( $row['HasSeen']);
			$this->_File_assign->setCreationDate( $row['CreationDate']);
			$this->_File_assign->setApproveDate( $row['ApproveDate']);
			$this->_File_assign->setAssignDate( $row['AssignDate']);




		    $File_assignList[]=$this->_File_assign;

		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($File_assignList);

		return $Result;
	}

	
	
	public function searchFileID($FileID){

		$File_assignList = array();

		
		//echo "SELECT * FROM fms_file_assign WHERE CurrentUserID = $CurrentUser and IsPending = true";	
		$SQL = "SELECT * FROM fms_file_assign WHERE FileID = '".$FileID."' ";
		//echo $SQL;

		$this->_DB->doQuery($SQL);

		//WHERE CurrentUserID = $CurrentUser and IsPending = 1

		$rows = $this->_DB->getAllRows();

		//echo sizeof($rows);

		//

		//reading the top row for this File_assign from the database

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];

			$this->_File_assign = new File_assign();


			$this->_File_assign->setID( $row['ID']);
			$this->_File_assign->setFile( $row['FileID']);
			$this->_File_assign->setFileComment( $row['FileComment']);
			$this->_File_assign->setIsApproved( $row['IsApproved']);
			$this->_File_assign->setIsRejected( $row['IsRejected']);

			$this->_File_assign->setPreviousUser( $row['PreviousUserID']);
			$this->_File_assign->setCurrentUser( $row['CurrentUserID']);
			$this->_File_assign->setIsPending( $row['IsPending']);
			$this->_File_assign->setHasSeen( $row['HasSeen']);
			$this->_File_assign->setCreationDate( $row['CreationDate']);
			$this->_File_assign->setApproveDate( $row['ApproveDate']);
			$this->_File_assign->setAssignDate( $row['AssignDate']);




		    $File_assignList[]=$this->_File_assign;

		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($File_assignList);

		return $Result;
	}	

	//update an File_assign object based on its 
	public function updateFile_assign($File_assign){

		//

		$ID = $File_assign->getID();
		$FileID=$File_assign->getFile();
		$FileComment=$File_assign->getFileComment();
		$IsApproved=$File_assign->getIsApproved();
		$IsRejected=$File_assign->getIsRejected();
		$CurrentUserID=$File_assign->getCurrentUser();
		$PreviousUserID=$File_assign->getPreviousUser();
		$IsPending=$File_assign->getIsPending();
		$HasSeen=$File_assign->getHasSeen();
		$CreationDate=$File_assign->getCreationDate();
		$ApproveDate=$File_assign->getApproveDate();
		$AssignDate=$File_assign->getAssignDate();




		//$SQL = "INSERT INTO fms_file_assign(ID, FileID, FileComment, IsApproved, IsRejected, PreviousUserID, CurrentUserID, IsPending, HasSeen, CreationDate, ApproveDate, AssignDate) VALUES('$ID','$FileID','$FileComment', '$IsApproved', '$IsRejected', '$PreviousUserID', '$CurrentUserID', '$IsPending', '$HasSeen', '$CreationDate', '$ApproveDate', '$AssignDate')";

		//



		$SQL = "UPDATE fms_file_assign SET FileID = '".$FileID."', FileComment = '".$FileComment."', IsApproved = '".$IsApproved."', IsRejected = '".$IsRejected."', PreviousUserID = '".$PreviousUserID."', CurrentUserID = '".$CurrentUserID."', IsPending = '".$IsPending."', HasSeen = '".$HasSeen."', CreationDate = '".$CreationDate."', ApproveDate = '".$ApproveDate."', AssignDate = '".$AssignDate."' WHERE ID = '".$ID."'";

		echo $SQL;

		//$SQL = "UPDATE fms_file_assign SET FileID = $FileID WHERE ID='".$File_assign->getID()."'  ";
///////////next code goes from here....

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an File_assign based on its id of the database
	public function deleteFile_assign($File_assign){


		$SQL = "DELETE from fms_file_assign where ID ='".$File_assign->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//echo '<br> log:: exit the class.File_assigndao.inc';

?>