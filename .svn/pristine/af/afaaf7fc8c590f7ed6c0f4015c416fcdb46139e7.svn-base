<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.job.inc';

Class JobDAO{
	private $_DB;
	private $_Job;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Job = new Job();
	}

	//create new job request with the job object
	public function newJobRequest($Job){

		$Title=$Job->getTitle();
		$Subtitle=$Job->getSubtitle();
		$PublishDate=date("Y-m-d");
		$Organization=$Job->getOrganization();
		$Qualification=$Job->getQualification();
		$Gender=$Job->getGender();
		$AgeLimit = $Job->getAgeLimit();
		$EmploymentType=$Job->getEmploymentType();
		$NumberOfVacancy=$Job->getNumberOfVacancy();
		$Email=$Job->getEmail();
		$ContactNumber = $Job->getContactNumber();	
		$Salary=$Job->getSalary();
		$Location=$Job->getLocation();
		$JobExperience=$Job->getJobExperience();
		$LastDateOfApplication = $Job->getLastDateOfApplication();	


		$SQL = "INSERT INTO jms_job(Title,Subtitle,PublishDate,Organization,Qualification,Gender,AgeLimit,EmploymentType,NumberOfVacancy,Email,ContactNumber,Salary,Location,JobExperience,LastDateOfApplication)

		 	VALUES('$Title','$Subtitle','$PublishDate','$Organization','$Qualification','$Gender','$AgeLimit','$EmploymentType','$NumberOfVacancy','$Email','$ContactNumber','$Salary','$Location','$JobExperience','$LastDateOfApplication')";

		//echo $SQL; 	

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the Job
		$SQL = $this->_DB->doQuery($SQL);	
	
		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("New Job Request Submitted Successfully.");

		return $Result;
	}

}
?>