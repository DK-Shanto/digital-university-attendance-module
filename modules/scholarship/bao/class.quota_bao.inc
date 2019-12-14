<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'dao/class.quota_dao.inc';


/*
	Quota Process Object 
*/
Class QuotaBAO{

	private $_DB;
	private $_QuotaDAO;

	public function __construct(){

		$this->_QuotaDAO = new QuotaDAO();

	}

	//new Quota post request funtion with the Quota object
	public function newQuotaRequest($Quota){

		$Result = new Result();	
		$Result = $this->_QuotaDAO->newQuotaRequest($Quota);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuotaDAO.newQuotaRequest()");		

		return $Result;
	}

	//get all Quota information
	public function getAllQuotas(){

		$Result = new Result();	
		$Result = $this->_QuotaDAO->getAllQuotas();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuotaDAO.getAllQuotas()");		

		return $Result;
	}

	//delete an existing Quota
	public function deleteQuota($Quota){

		$Result = new Result();	
		$Result = $this->_QuotaDAO->deleteQuota($Quota);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuotaDAO.deleteQuota()");		

		return $Result;

	}


	//read an Quota object based on its id form Quota object
	public function readQuota($Quota){


		$Result = new Result();	
		$Result = $this->_QuotaDAO->readQuota($Quota);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuotaDAO.readQuota()");		

		return $Result;


	}

	//update an Quota object based on its current information
	public function updateQuota($Quota){

		$Result = new Result();	
		$Result = $this->_QuotaDAO->updateQuota($Quota);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuotaDAO.updateQuota()");		

		return $Result;
	}



}

?>