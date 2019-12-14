<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.file.inc';
include_once UTILITY.'class.util.inc';

Class FileDAO{

	private $_DB;
	private $_File;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_File = new File();

	}

	// get all the Files from the database using the database query
	public function getAllFiles(){
		$globalUser = $_SESSION['globalUser'];

		$user_id = $globalUser->getID();
		//echo ($user_id);

		$FileList = array();

		//$this->_DB->doQuery("SELECT * FROM fms_file WHERE CreatorID = '$user_id'");
		$this->_DB->doQuery("SELECT fms_file.ID,CreatorID,Name,Link,Receiver,Comment,Timestamp,ums_user.DisciplineID
FROM fms_file,ums_user
WHERE fms_file.CreatorID = '$user_id' AND fms_file.Receiver = ums_user.ID");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_File = new File();

		    $this->_File->setID ( $row['ID']);
		    $this->_File->setCreator( $row['CreatorID'] );
		    $this->_File->setName( $row['Name'] );
		    $this->_File->setLink( $row['Link'] );
		    $this->_File->setDiscipline( $row['DisciplineID'] );
		    $this->_File->setComment($row['Comment']);
		    $this->_File->setTimestamp($row['Timestamp']);






		    $FileList[]=$this->_File;

		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($FileList);

		return $Result;
	}


    public function updateCurrentUser($File)
    {
        $globalUser = $_SESSION['globalUser'];

        $newCurrentUser = $File->getCurrentUser();
        $fileId = $File->getID();

        $this->_DB->doQuery("UPDATE fms_file
					SET fms_file.CurrentUser = '$newCurrentUser'
						WHERE fms_file.ID = '$fileId'");

        $Result = new Result();
        $Result->setIsSuccess(1);
        //$Result->setResultObject($FileList);

        return $Result;


    }



	public function getAllReceivedFiles(){
		$globalUser = $_SESSION['globalUser'];

		$user_id = $globalUser->getID();
		//echo ($user_id);

		$FileList = array();

		//$this->_DB->doQuery("SELECT * FROM fms_file WHERE Receiver = '$user_id'");
        $this->_DB->doQuery("SELECT fms_file.ID,CreatorID,Name,Link,Receiver,Comment,Timestamp,ums_user.DisciplineID
FROM fms_file,ums_user
WHERE fms_file.Receiver = '$user_id' AND fms_file.CreatorID = ums_user.ID");



		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_File = new File();

		    $this->_File->setID ( $row['ID']);
		    $this->_File->setCreator( $row['CreatorID'] );
		    $this->_File->setName( $row['Name'] );
		    $this->_File->setLink( $row['Link'] );
		    $this->_File->setDiscipline( $row['DisciplineID'] );
		    $this->_File->setComment($row['Comment']);
		    $this->_File->setTimestamp($row['Timestamp']);






		    $FileList[]=$this->_File;

		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($FileList);

		return $Result;
	}

	//create File funtion with the File object
	public function createFile($File){

		$ID=$File->getID();
		$Comment = $File->getComment();
		$Creator=$File->getCreator();
		$Name=$File->getName();
		$Link=$File->getLink();
		$DisciplineID=$File->getDiscipline();




		$SQL = "INSERT INTO fms_file(ID,CreatorID,Name,Link,DisciplineID,Comment,Timestamp,Receiver) VALUES('$ID','$Creator', '$Name', '$Link', '$DisciplineID', '$Comment', now(), '$Name')";



		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}


	//create file second function
    public function createFile2($File){

        $ID=$File->getID();
        $Creator=$File->getCreator();
        $Link=$File->getLink();
        $CurrentUser = $File->getCurrentUser();





        $SQL = "INSERT INTO fms_file(ID,Link,CreatorID,CurrentUser) VALUES('$ID','$Link', '$Creator', '$CurrentUser')";




        $SQL = $this->_DB->doQuery($SQL);

        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }


	//read an File object based on its id form File object
	public function readFile($File){


		$SQL = "SELECT * FROM fms_file WHERE ID='".$File->getID()."'";

		//echo $SQL;
		$this->_DB->doQuery($SQL);

		//reading the top row for this File from the database
		$row = $this->_DB->getTopRow();

		$this->_File = new File();

		//preparing the File object
	    $this->_File->setID ( $row['ID']);
	    $this->_File->setName( $row['Name'] );
	    $this->_File->setLink($row['Link']);


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_File);

		return $Result;
	}

	//update an File object based on its
	public function updateFile($File){

		//$SQL = "UPDATE fms_file SET Name='".$File->getName()."' WHERE ID='".$File->getID()."'";

		$SQL = "UPDATE fms_file SET Name='".$File->getName()."',
			Link='".$File->getLink()."',
			DisciplineID='".$File->getDiscipline()."' WHERE ID='".$File->getID()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an File based on its id of the database
	public function deleteFile($File){


		$SQL = "DELETE from fms_file where ID ='".$File->getID()."'";

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}


	public function updateFileLink($File)
	{
        $globalUser = $_SESSION['globalUser'];

        $newCurrentUser = $File->getCurrentUser();
        $fileId = $File->getID();
        $fileLink = $File->getLink();

        $this->_DB->doQuery("UPDATE fms_file
					SET fms_file.CurrentUser = '$newCurrentUser', fms_file.Link = '$fileLink'
						WHERE fms_file.ID = '$fileId'");

        $Result = new Result();
        $Result->setIsSuccess(1);
        //$Result->setResultObject($FileList);

        return $Result;

	}

}

//echo '<br> log:: exit the class.filedao.inc';

?>
