<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'dao/class.display_scholarship_dao.inc';



/*
	Scholarship Process Object 
*/
Class ScholarshipBAO{

	private $_DB;
	private $_ScholarshipDAO;

	public function __construct(){

		$this->_ScholarshipDAO = new ScholarshipDAO();

	}


	//get all scholarship information
	public function getAllScholarships(){

		$Result = new Result();	
		$Result = $this->_ScholarshipDAO->getAllScholarships();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ScholarshipDAO.getAllScholarships()");		

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
	public function readStudent($Student){


		$Result = new Result();	
		$Result = $this->_StudentDAO->readStudent($Student);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentDAO.readStudent()");		

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


Class StudentHasScholarshipBAO{

	private $_DB;
	private $_StudentHasScholarshipDAO;

	public function __construct(){

		$this->_StudentHasScholarshipDAO = new StudentHasScholarshipDAO();

	}

	//new StudentHasScholarship post request funtion with the StudentHasScholarship object
	public function newStudentHasScholarshipRequest($StudentHasScholarship){

		$Result = new Result();	
		$Result = $this->_StudentHasScholarshipDAO->newStudentHasScholarshipRequest($StudentHasScholarship);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentHasScholarshipDAO.newStudentHasScholarshipRequest()");		

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

	//new StudentHasScholarship post request funtion with the StudentHasScholarship object
	public function getStudentHasScholarshipByUniversityID($User){

		$Result = new Result();	
		$Result = $this->_StudentHasScholarshipDAO->getStudentHasScholarshipByUniversityID($User);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentHasScholarshipDAO.getStudentHasScholarshipByUniversityID()");		

		return $Result;
	}


}


?>