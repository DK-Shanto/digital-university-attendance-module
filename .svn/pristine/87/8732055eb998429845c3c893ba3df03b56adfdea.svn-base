<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_JOB.'dao/class.job_cv_create_dao.inc';

Class JobCVCreateBAO{

	private $_DB;
	private $_JobCVCreateDAO;

	public function __construct(){

		$this->_JobCVCreateDAO = new JobCVCreateDAO();

	}

	public function newJobCVCreateRequest($CV){

		$Result = new Result();	
		$Result = $this->_JobCVCreateDAO->newJobCVCreateRequest($CV);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in JobDAO.newJobRequest()");		

		return $Result;

	
	}
	public function JobCVUpdateRequest($CV){

		$Result = new Result();	
		$Result = $this->_JobCVCreateDAO->JobCVUpdateRequest($CV);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in JobDAO.newJobRequest()");		

		return $Result;

	
	}

}

?>