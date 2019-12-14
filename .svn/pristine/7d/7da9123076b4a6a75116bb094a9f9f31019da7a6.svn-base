<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.scholarship.inc';

Class CatagoryDAO{

	private $_DB;
	private $_Catagory;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Catagory = new Catagory();
	}


		//create new catagory request with the catagory object
	public function newCatagoryRequest($Catagory){

		$CatagoryName=$Catagory->getCatagoryName();
		$ShortName=$Catagory->getShortName();


		$SQL = "INSERT INTO sms_scholarship_catagory(catagoryName,shortName)

		 	VALUES('$CatagoryName','$ShortName')";

		//echo $SQL; 	

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the Job
		$SQL = $this->_DB->doQuery($SQL);	
	
		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("New Catagory Request Submitted Successfully.");

		return $Result;
	}


	// get all the catagories from the database using the database query
	public function getAllCatagorys(){

		$CatagoryList = array();

		// $this->_DB->doQuery("SELECT * FROM ums_user where IsDeleted is null 
		// 	order by (UniversityID * 1) ASC");
		$this->_DB->doQuery("SELECT * FROM sms_scholarship_catagory
			order by (id * 1) ASC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Catagory = new Catagory();

			$this->_Catagory->setID ( $row['id']);
		    $this->_Catagory->setCatagoryName ( $row['catagoryName']);
		    $this->_Catagory->setShortName ( $row['shortName'] );

		    $CatagoryList[]=$this->_Catagory;
   
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CatagoryList);

		return $Result;
	}



	

	//delete an user based on its id of the database
	public function deleteCatagory($Catagory){

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
	
		//removing previous Positions 

		$SQL_delete = "DELETE from sms_scholarship_catagory where id ='".$Catagory->getID()."'";
		$SQL_delete = $this->_DB->doQuery($SQL_delete);


		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Catagory Deleted Successfully.");

		return $Result;

	}


	public function readCatagory($Catagory){

		$SQL = "SELECT * from sms_scholarship_catagory where id ='".$Catagory->getID()."'";

		$this->_DB->doQuery($SQL);

		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		$this->_Catagory = new Catagory();

		$this->_Catagory->setID ( $row['id']);
	    $this->_Catagory->setCatagoryName ( $row['catagoryName']);
	    $this->_Catagory->setShortName ( $row['shortName'] );

	    $Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Catagory);

		return $Result;
	}


	//update an catagory object based on its id information
	public function updateCatagory($Catagory){

		$ID = $Catagory->getID();
		$CatagoryName=$Catagory->getCatagoryName();
		$ShortName=$Catagory->getShortName();


		$SQL = "UPDATE sms_scholarship_catagory SET 
			catagoryName='$CatagoryName', shortName='$ShortName' WHERE id='$ID'";

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//updating the user
		$SQL = $this->_DB->doQuery($SQL);
				
		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Catagory updated Successfully");

		return $Result;

	}

}


?>