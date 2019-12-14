<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'dao/class.upload_cv_dao.inc';
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

	//new Student post request funtion with the Student object
	public function updateStudent($Student){

		$Result = new Result();	
		$Result = $this->_StudentDAO->updateStudent($Student);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in StudentDAO.newStudentRequest()");		

		return $Result;
	}


}

?>