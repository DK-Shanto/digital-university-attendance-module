<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'dao/class.achieved_scholarship_dao.inc';



Class ScholarshipBAO{

	private $_DB;
	private $_ScholarshipDAO;

	public function __construct(){

		$this->_ScholarshipDAO = new ScholarshipDAO();

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


Class StudentHasScholarshipBAO{

	private $_DB;
	private $_StudentHasScholarshipDAO;

	public function __construct(){

		$this->_StudentHasScholarshipDAO = new StudentHasScholarshipDAO();

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
