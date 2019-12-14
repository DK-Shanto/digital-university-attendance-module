<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'dao/class.post_scholarship_dao.inc';



/*
	Scholarship Process Object 
*/
Class ScholarshipBAO{

	private $_DB;
	private $_ScholarshipDAO;

	public function __construct(){

		$this->_ScholarshipDAO = new ScholarshipDAO();

	}

	//new Scholarship post request funtion with the Scholarship object
	public function newScholarshipRequest($Scholarship){

		$Result = new Result();	
		$Result = $this->_ScholarshipDAO->newScholarshipRequest($Scholarship);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ScholarshipDAO.newScholarshipRequest()");		

		return $Result;
	}

	//get all scholarship information
	public function getAllScholarships(){

		$Result = new Result();	
		$Result = $this->_ScholarshipDAO->getAllScholarships();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ScholarshipDAO.getAllScholarships()");		

		return $Result;
	}

	//delete an existing scholarship
	public function deleteScholarship($Scholarship){

		$Result = new Result();	
		$Result = $this->_ScholarshipDAO->deleteScholarship($Scholarship);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ScholarshipDAO.deleteScholarship()");		

		return $Result;

	}

	//read an scholarship object based on its id form scholarship object
	public function readScholarship($Scholarship){


		$Result = new Result();	
		$Result = $this->_ScholarshipDAO->readScholarship($Scholarship);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ScholarshipDAO.readScholarship()");		

		return $Result;


	}


	//update an scholarship object based on its current information
	public function updateScholarship($Scholarship){

		$Result = new Result();	
		$Result = $this->_ScholarshipDAO->updateScholarship($Scholarship);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ScholarshipDAO.updateScholarship()");		

		return $Result;
	}


}

?>