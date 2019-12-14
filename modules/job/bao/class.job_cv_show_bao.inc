<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_JOB.'dao/class.job_cv_show_dao.inc';


Class JobCVShowBAO{

	private $_DB;
	private $_JobCVShowDAO;

	public function __construct(){

		$this->_JobCVShowDAO = new JobCVShowDAO();

	}

	public function getCV($globalUser){

		$Result = new Result();	
		$Result = $this->_JobCVShowDAO->getCV($globalUser);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in JobListDAO.getAllJobs()");		

		return $Result;
	}
}
?>