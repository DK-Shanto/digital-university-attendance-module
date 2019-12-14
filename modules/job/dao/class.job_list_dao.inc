<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.job.inc';
include_once COMMON.'class.common.user.inc';


Class JobListDAO{

	private $_DB;
	private $_Job;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Job = new Job();
	}

	// get all the users from the database using the database query
	public function getAllJobs(){

		$JobList = array();

		$this->_DB->doQuery("SELECT * FROM jms_job");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Job = new Job();

		    $this->_Job->setID ( $row['ID']);
		    $this->_Job->setTitle ( $row['Title'] );   
		    $this->_Job->setSubtitle ( $row['Subtitle'] );
		    $this->_Job->setPublishDate ( $row['PublishDate'] );
		    $this->_Job->setOrganization( $row['Organization'] );
		    $this->_Job->setQualification( $row['Qualification'] );
		    $this->_Job->setGender( $row['Gender'] );
		    $this->_Job->setAgeLimit ( $row['AgeLimit'] );
		    $this->_Job->setEmploymentType( $row['EmploymentType'] );
		    $this->_Job->setNumberOfVacancy( $row['NumberOfVacancy'] );
		    $this->_Job->setEmail( $row['Email'] );
		    $this->_Job->setContactNumber ( $row['ContactNumber'] );
		    $this->_Job->setSalary( $row['Salary'] );
		    $this->_Job->setLocation( $row['Location'] );
		    $this->_Job->setJobExperience( $row['JobExperience'] );
		    $this->_Job->setLastDateOfApplication( $row['LastDateOfApplication'] );


		    $JobList[]=$this->_Job;
   
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($JobList);

		return $Result;
	}
	//read an job object based on its id form job object along with the Positions
	public function readJobPositions($Job){

		$this->_DB->doQuery("SELECT * FROM jms_job where ID like '".$Job->getID()."'");

		$rows = $this->_DB->getAllRows();
		$row = $rows[0];
		$this->_Job = new Job();

	    $this->_Job->setID ( $row['ID']);
	    $this->_Job->setTitle ( $row['Title'] );   
	    $this->_Job->setSubtitle ( $row['Subtitle'] );
	    $this->_Job->setPublishDate ( $row['PublishDate'] );
	    $this->_Job->setOrganization( $row['Organization'] );
	    $this->_Job->setQualification( $row['Qualification'] );
	    $this->_Job->setGender( $row['Gender'] );
	    $this->_Job->setAgeLimit ( $row['AgeLimit'] );
	    $this->_Job->setEmploymentType( $row['EmploymentType'] );
	    $this->_Job->setNumberOfVacancy( $row['NumberOfVacancy'] );
	    $this->_Job->setEmail( $row['Email'] );
	    $this->_Job->setContactNumber ( $row['ContactNumber'] );
	    $this->_Job->setSalary( $row['Salary'] );
	    $this->_Job->setLocation( $row['Location'] );
	    $this->_Job->setJobExperience( $row['JobExperience'] );
	    $this->_Job->setLastDateOfApplication( $row['LastDateOfApplication'] );

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Job);

		return $Result;
	}
	//delete an job based on its id of the database
	public function deleteJob($Job){
	
		//removing previous Positions 

		$ID=$Job->getID();

		$SQL_delete = "DELETE from jms_job where ID like '$ID'";
		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		$SQL_delete = $this->_DB->doQuery($SQL_delete);
		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Job Deleted Successfully.");

		return $Result;

	}
	//create new job request with the job object
	public function updateJobRequest($Job){

		$ID=$Job->getID();
		$Title=$Job->getTitle();
		$Subtitle=$Job->getSubtitle();
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


		$SQL = "UPDATE jms_job SET Title='$Title',Subtitle='$Subtitle',Organization='$Organization',Qualification='$Qualification',Gender='$Gender',AgeLimit='$AgeLimit',EmploymentType='$EmploymentType',NumberOfVacancy='$NumberOfVacancy',Email='$Email',ContactNumber='$ContactNumber',Salary='$Salary',Location='$Location',JobExperience='$JobExperience',LastDateOfApplication='$LastDateOfApplication' WHERE ID='$ID'";

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the Job
		$SQL = $this->_DB->doQuery($SQL);	
	
		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Job Updated Successfully.");

		return $Result;
	}
	public function checkForCV($UserDetails){
		$this->_DB->doQuery("SELECT * FROM jms_cv where applicantID like '".$UserDetails->getID()."'");

		$rows = $this->_DB->getAllRows();
		if(sizeof($rows)>0)
		{
			$row = $rows[0];
			$cvID= $row['ID'];

			$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject($cvID);
		}
		else
		{
			$Result = new Result();
			$Result->setIsSuccess(1);
		}
		return $Result;
	}
	public function applyJob($Applicant){
		$applicantID=$Applicant->getapplicantID();
		$JobID=$Applicant->getJobID();
		$cvID=$Applicant->getcvID();
		$SubmissionDate=$Applicant->getSubmissionDate();

		$this->_DB->doQuery("SELECT * FROM jms_applicant where JobID like '$JobID' and cvID like '$cvID'");

		$rows = $this->_DB->getAllRows();
		if(sizeof($rows)>0)
		{
			$row = $rows[0];
			$cvID= $row['ID'];

			$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject("You have already applied for this Job");
		}
		else
		{
			$SQL = "INSERT INTO jms_applicant(applicantID,JobID,cvID,SubmissionDate)
			 	VALUES('$applicantID','$JobID','$cvID','$SubmissionDate')";

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
		}

		return $Result;
	}

	// // get all the users from the database using the database query
	// public function getJobDetails($Job){

	// 	$id=$Job->getID();

	// 	$this->_DB->doQuery("SELECT * FROM jms_job where ID like '$id'");

	// 	$rows = $this->_DB->getAllRows();

	// 		$row = $rows[0];
	// 		$this->_Job = new Job();

	// 	    $this->_Job->setID ( $row['ID']);
	// 	    $this->_Job->setTitle ( $row['Title'] );   
	// 	    $this->_Job->setSubtitle ( $row['Subtitle'] );
	// 	    $this->_Job->setPublishDate ( $row['PublishDate'] );
	// 	    $this->_Job->setOrganization( $row['Organization'] );
	// 	    $this->_Job->setQualification( $row['Qualification'] );
	// 	    $this->_Job->setGender( $row['Gender'] );
	// 	    $this->_Job->setAgeLimit ( $row['AgeLimit'] );
	// 	    $this->_Job->setEmploymentType( $row['EmploymentType'] );
	// 	    $this->_Job->setNumberOfVacancy( $row['NumberOfVacancy'] );
	// 	    $this->_Job->setEmail( $row['Email'] );
	// 	    $this->_Job->setContactNumber ( $row['ContactNumber'] );
	// 	    $this->_Job->setSalary( $row['Salary'] );
	// 	    $this->_Job->setLocation( $row['Location'] );
	// 	    $this->_Job->setJobExperience( $row['JobExperience'] );
	// 	    $this->_Job->setLastDateOfApplication( $row['LastDateOfApplication'] );


	// 	$Result = new Result();
	// 	$Result->setIsSuccess(1);
	// 	$Result->setResultObject($this->_Job);

	// 	return $Result;
	// }
}

?>