<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_JOB.'dao/class.job_list_dao.inc';


Class JobListBAO{

	private $_DB;
	private $_JobListDAO;

	public function __construct(){

		$this->_JobListDAO = new JobListDAO();

	}

	public function getAllJobs(){

		$Result = new Result();	
		$Result = $this->_JobListDAO->getAllJobs();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in JobListDAO.getAllJobs()");		

		return $Result;
	}
	public function readJobPositions($Job){


		$Result = new Result();	
		$Result = $this->_JobListDAO->readJobPositions($Job);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.readUserRolesPositions()");		

		return $Result;


	}
	public function deleteJob($Job){

		$Result = new Result();	
		$Result = $this->_JobListDAO->deleteJob($Job);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.deleteUser()");		

		return $Result;

	}
	public function updateJobRequest($Job){

		$Result = new Result();	
		$Result = $this->_JobListDAO->updateJobRequest($Job);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.updateUser()");		

		return $Result;
	}

	public function checkForCV($UserDetails){
		$Result = new Result();	
		$Result = $this->_JobListDAO->checkForCV($UserDetails);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.readUserDetails()");		

		return $Result;
	}

	public function applyJob($Applicant){
		$Result = new Result();	
		$Result = $this->_JobListDAO->applyJob($Applicant);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.readUserDetails()");		

		return $Result;
	}
	public function getJobDetails($Job){
		$Result = new Result();	
		$Result = $this->_JobListDAO->getJobDetails($Job);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UserDAO.readUserDetails()");		

		return $Result;
	}
}
?>