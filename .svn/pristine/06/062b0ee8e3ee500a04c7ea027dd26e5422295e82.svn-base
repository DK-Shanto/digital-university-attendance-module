<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.scholarship.inc';

Class CocurricularDAO{

	private $_DB;
	private $_Cocurricular;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Cocurricular = new Cocurricular();
	}


		//create new Cocurricular request with the Cocurricular object
	public function newCocurricularRequest($Cocurricular){

		$CocurricularName=$Cocurricular->getCocurricularName();
		$ShortName=$Cocurricular->getShortName();


		$SQL = "INSERT INTO sms_scholarship_cocurricular(coName,shortName)

		 	VALUES('$CocurricularName','$ShortName')";

		//echo $SQL; 	

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the Job
		$SQL = $this->_DB->doQuery($SQL);	
	
		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("New Cocurricular Request Submitted Successfully.");

		return $Result;
	}


	// get all the catagories from the database using the database query
	public function getAllCocurriculars(){

		$CocurricularList = array();

		// $this->_DB->doQuery("SELECT * FROM ums_user where IsDeleted is null 
		// 	order by (UniversityID * 1) ASC");
		$this->_DB->doQuery("SELECT * FROM sms_scholarship_cocurricular
			order by (id * 1) ASC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Cocurricular = new Cocurricular();

			$this->_Cocurricular->setID ( $row['id']);
		    $this->_Cocurricular->setCocurricularName ( $row['coName']);
		    $this->_Cocurricular->setShortName ( $row['shortName'] );

		    $CocurricularList[]=$this->_Cocurricular;
   
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CocurricularList);

		return $Result;
	}



	

	//delete an user based on its id of the database
	public function deleteCocurricular($Cocurricular){

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
	
		//removing previous Positions 

		$SQL_delete = "DELETE from sms_scholarship_cocurricular where id ='".$Cocurricular->getID()."'";
		$SQL_delete = $this->_DB->doQuery($SQL_delete);


		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Cocurricular Deleted Successfully.");

		return $Result;

	}


	public function readCocurricular($Cocurricular){

		$SQL = "SELECT * from sms_scholarship_cocurricular where id ='".$Cocurricular->getID()."'";

		$this->_DB->doQuery($SQL);

		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		$this->_Cocurricular = new Cocurricular();

		$this->_Cocurricular->setID ( $row['id']);
	    $this->_Cocurricular->setCocurricularName ( $row['coName']);
	    $this->_Cocurricular->setShortName ( $row['shortName'] );

	    $Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Cocurricular);

		return $Result;
	}


	//update an Cocurricular object based on its id information
	public function updateCocurricular($Cocurricular){

		$ID = $Cocurricular->getID();
		$CocurricularName=$Cocurricular->getCocurricularName();
		$ShortName=$Cocurricular->getShortName();


		$SQL = "UPDATE sms_scholarship_cocurricular SET 
			coName='$CocurricularName', shortName='$ShortName' WHERE id='$ID'";

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//updating the user
		$SQL = $this->_DB->doQuery($SQL);
				
		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Cocurricular updated Successfully");

		return $Result;

	}

}


?>