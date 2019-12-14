<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'dao/class.applied_scholarship_dao.inc';



/*
	AppliedScholarship Process Object 
*/
Class AppliedScholarshipBAO{

	private $_DB;
	private $_AppliedScholarshipDAO;

	public function __construct(){

		$this->_AppliedScholarshipDAO = new AppliedScholarshipDAO();

	}


	//get all AppliedScholarship information
	public function getAllAppliedScholarships(){

		$Result = new Result();	
		$Result = $this->_AppliedScholarshipDAO->getAllAppliedScholarships();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in AppliedScholarshipDAO.getAllAppliedScholarships()");		

		return $Result;
	}
}


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


Class StudentHasScholarshipBAO{

	private $_DB;
	private $_StudentHasScholarshipDAO;

	public function __construct(){

		$this->_StudentHasScholarshipDAO = new StudentHasScholarshipDAO();

	}

	//new StudentHasScholarship post request funtion with the StudentHasScholarship object
	public function getStudentHasScholarshipByScholarshipID($Scholarship){

		$Result = new Result();	
		$Result = $this->_StudentHasScholarshipDAO->getStudentHasScholarshipByScholarshipID($Scholarship);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentHasScholarshipDAO.newStudentHasScholarshipRequest()");		

		return $Result;
	}

	//new StudentHasScholarship post request funtion with the StudentHasScholarship object
	public function getAllStudentsByScholarshipId($Scholarship){

		$Result = new Result();	
		$Result = $this->_StudentHasScholarshipDAO->getAllStudentsByScholarshipId($Scholarship);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentHasScholarshipDAO.getAllStudentsByScholarshipId()");		

		return $Result;
	}

	//new StudentHasScholarship post request funtion with the StudentHasScholarship object
	public function getAllUsersByScholarshipId($Scholarship){

		$Result = new Result();	
		$Result = $this->_StudentHasScholarshipDAO->getAllUsersByScholarshipId($Scholarship);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentHasScholarshipDAO.getAllUsersByScholarshipId()");		

		return $Result;
	}

	//get all StudentHasScholarship information
	public function getAllStudentHasScholarships(){

		$Result = new Result();	
		$Result = $this->_StudentHasScholarshipDAO->getAllStudentHasScholarships();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentHasScholarshipDAO.getAllStudentHasScholarships()");		

		return $Result;
	}

	//read an StudentHasScholarship object based on its id form StudentHasScholarship object
	public function readStudentHasScholarship($StudentHasScholarship){


		$Result = new Result();	
		$Result = $this->_StudentHasScholarshipDAO->readStudentHasScholarship($StudentHasScholarship);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentHasScholarshipDAO.readStudentHasScholarship()");		

		return $Result;


	}

	//read an StudentHasScholarship object based on its id form StudentHasScholarship object
	public function updateStudentHasScholarshipPriority($StudentHasScholarship){


		$Result = new Result();	
		$Result = $this->_StudentHasScholarshipDAO->updateStudentHasScholarshipPriority($StudentHasScholarship);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentHasScholarshipDAO.updateStudentHasScholarshipPriority()");		

		return $Result;


	}

	//read an StudentHasScholarship object based on its id form StudentHasScholarship object
	public function updateStudentHasScholarshipStatus($StudentHasScholarship){


		$Result = new Result();	
		$Result = $this->_StudentHasScholarshipDAO->updateStudentHasScholarshipStatus($StudentHasScholarship);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentHasScholarshipDAO.updateStudentHasScholarshipStatus()");		

		return $Result;


	}


}


Class StudentBAO{

	private $_DB;
	private $_StudentDAO;

	public function __construct(){

		$this->_StudentDAO = new StudentDAO();

	}

	//new Student post request funtion with the Student object
	public function newStudentRequest($Student){

		$Result = new Result();	
		$Result = $this->_StudentDAO->newStudentRequest($Student);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentDAO.newStudentRequest()");		

		return $Result;
	}

	//get all Student information
	public function getAllStudents(){

		$Result = new Result();	
		$Result = $this->_StudentDAO->getAllStudents();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentDAO.getAllStudents()");		

		return $Result;
	}

	//read an Student object based on its id form Student object
	public function readStudentByUniversityID($Student){


		$Result = new Result();	
		$Result = $this->_StudentDAO->readStudentByUniversityID($Student);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentDAO.readStudentByUniversityID()");		

		return $Result;


	}


}


?>


