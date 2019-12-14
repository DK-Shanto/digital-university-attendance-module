<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.scholarship.inc';

Class QuotaDAO{

	private $_DB;
	private $_Quota;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Quota = new Quota();
	}


		//create new Quota request with the Quota object
	public function newQuotaRequest($Quota){

		$QuotaName=$Quota->getQuotaName();
		$ShortName=$Quota->getShortName();


		$SQL = "INSERT INTO sms_scholarship_quota(quotaName,shortName)

		 	VALUES('$QuotaName','$ShortName')";

		//echo $SQL; 	

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the Job
		$SQL = $this->_DB->doQuery($SQL);	
	
		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("New Quota Request Submitted Successfully.");

		return $Result;
	}


	// get all the catagories from the database using the database query
	public function getAllQuotas(){

		$QuotaList = array();

		// $this->_DB->doQuery("SELECT * FROM ums_user where IsDeleted is null 
		// 	order by (UniversityID * 1) ASC");
		$this->_DB->doQuery("SELECT * FROM sms_scholarship_quota
			order by (id * 1) ASC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Quota = new Quota();

			$this->_Quota->setID ( $row['id']);
		    $this->_Quota->setQuotaName ( $row['quotaName']);
		    $this->_Quota->setShortName ( $row['shortName'] );

		    $QuotaList[]=$this->_Quota;
   
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($QuotaList);

		return $Result;
	}



	

	//delete an user based on its id of the database
	public function deleteQuota($Quota){

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
	
		//removing previous Positions 

		$SQL_delete = "DELETE from sms_scholarship_quota where id ='".$Quota->getID()."'";
		$SQL_delete = $this->_DB->doQuery($SQL_delete);


		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Quota Deleted Successfully.");

		return $Result;

	}


	public function readQuota($Quota){

		$SQL = "SELECT * from sms_scholarship_quota where id ='".$Quota->getID()."'";

		$this->_DB->doQuery($SQL);

		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		$this->_Quota = new Quota();

		$this->_Quota->setID ( $row['id']);
	    $this->_Quota->setQuotaName ( $row['quotaName']);
	    $this->_Quota->setShortName ( $row['shortName'] );

	    $Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Quota);

		return $Result;
	}


	//update an Quota object based on its id information
	public function updateQuota($Quota){

		$ID = $Quota->getID();
		$QuotaName=$Quota->getQuotaName();
		$ShortName=$Quota->getShortName();


		$SQL = "UPDATE sms_scholarship_quota SET 
			quotaName='$QuotaName', shortName='$ShortName' WHERE id='$ID'";

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//updating the user
		$SQL = $this->_DB->doQuery($SQL);
				
		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Quota updated Successfully");

		return $Result;

	}

}


?>