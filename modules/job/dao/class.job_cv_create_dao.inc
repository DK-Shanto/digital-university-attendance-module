<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.job.inc';

Class JobCVCreateDAO{
	private $_DB;
	private $_CV;
	private $_CV_Education;
	private $_CV_Experience;
	private $_CV_Skills;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_CV = new CV();
		$this->_CV_Education = new CV_Education();
		$this->_CV_Experience = new CV_Experience();
		$this->_CV_Skills = new CV_Skills();
	}

	public function newJobCVCreateRequest($CV){

		$applicantID=$CV->getapplicantID(); 

		$this->_DB->doQuery("SELECT * FROM ums_user where ID like '$applicantID'");

		$rows = $this->_DB->getAllRows();

		$row = $rows[0];

		$Name=$row['FirstName'].' '.$row['MiddleName'].' '.$row['LastName']; 
		$sector=$CV->getsector(); 
		$email=$CV->getemail(); 
		$phone=$CV->getphone(); 
		$profile=$CV->getprofile(); 
		$technical_skill=$CV->gettechnical_skill();
		$CV_Education=$CV->geteducation();
		$CV_Skills=$CV->getskills();
		$CV_Experience=$CV->getexperience();

		$this->_DB->doQuery("SELECT * FROM jms_cv where applicantID like '$applicantID'");

		$rows = $this->_DB->getAllRows();
		if(sizeof($rows)>0)
		{
			$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject("You have already created");
		}
		else
		{
		$SQL = "INSERT INTO jms_cv(applicantID,Name,sector,email,phone,profile,technical_skill)
		 	VALUES('$applicantID','$Name','$sector','$email','$phone','$profile','$technical_skill')";

		//echo $SQL; 	

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the Job
		$SQL = $this->_DB->doQuery($SQL);	
	
		//closing the transaction
		$this->_DB->getConnection()->commit();

		$this->_DB->doQuery("SELECT * FROM jms_cv where applicantID like '$applicantID'");

		$rows = $this->_DB->getAllRows();

		$row = $rows[0];
		$cvID= $row['ID'];

		for ($i=0; $i < sizeof($CV_Education); $i++) { 
			$Education = $CV_Education[$i];

			$SQL = "INSERT INTO jms_cv_education(cvID,instituition,subject,cgpa)
			 	VALUES('$cvID','".$Education->getinstituition()."','".$Education->getsubject()."','".$Education->getcgpa()."')";

			//echo $SQL; 	

			//beginning a transaction 	
			$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
			//creating the Job
			$SQL = $this->_DB->doQuery($SQL);	
		
			//closing the transaction
			$this->_DB->getConnection()->commit();

		}

		for ($i=0; $i < sizeof($CV_Skills); $i++) { 
			$Skill = $CV_Skills[$i];

			$SQL = "INSERT INTO jms_cv_skills(cvID,name,details)
				 	VALUES('$cvID','".$Skill->getname()."','".$Skill->getdetails()."')";

			//echo $SQL; 	

			//beginning a transaction 	
			$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
			//creating the Job
			$SQL = $this->_DB->doQuery($SQL);	
		
			//closing the transaction
			$this->_DB->getConnection()->commit();
		}

		for ($i=0; $i < sizeof($CV_Experience); $i++) { 
			$Experience = $CV_Experience[$i];

			$SQL = "INSERT INTO jms_cv_experience(cvID,jobname,jobposition,workingyear,workdetails)
				 	VALUES('$cvID','".$Experience->getjobname()."','".$Experience->getjobposition()."','".$Experience->getworkingyear()."','".$Experience->getworkdetails()."')";

			//echo $SQL; 	

			//beginning a transaction 	
			$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
			//creating the Job
			$SQL = $this->_DB->doQuery($SQL);	
		
			//closing the transaction
			$this->_DB->getConnection()->commit();
		}

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("New CV dropped Successfully.");
		}
		return $Result;
	}

	public function JobCVUpdateRequest($CV){

		$ID=$CV->getID();
		$applicantID=$CV->getapplicantID(); 
		$this->_DB->doQuery("SELECT * FROM ums_user where ID like '$applicantID'");

		$rows = $this->_DB->getAllRows();

		$row = $rows[0];

		$Name=$row['FirstName'].' '.$row['MiddleName'].' '.$row['LastName'];
		$sector=$CV->getsector(); 
		$email=$CV->getemail(); 
		$phone=$CV->getphone(); 
		$profile=$CV->getprofile(); 
		$technical_skill=$CV->gettechnical_skill();
		$CV_Education=$CV->geteducation();
		$CV_Skills=$CV->getskills();
		$CV_Experience=$CV->getexperience();

		$SQL = "DELETE FROM jms_cv where ID like '$ID'";

		$SQL = $this->_DB->doQuery($SQL);


		$SQL = "DELETE FROM jms_cv_education where cvID like '$ID'";

		$SQL = $this->_DB->doQuery($SQL);


		$SQL = "DELETE FROM jms_cv_skills where cvID like '$ID'";

		$SQL = $this->_DB->doQuery($SQL);


		$SQL = "DELETE FROM jms_cv_experience where cvID like '$ID'";

		$SQL = $this->_DB->doQuery($SQL);


		$SQL = "INSERT INTO jms_cv(applicantID,Name,sector,email,phone,profile,technical_skill)
		 	VALUES('$applicantID','$Name','$sector','$email','$phone','$profile','$technical_skill')";

		//echo $SQL; 	

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the Job
		$SQL = $this->_DB->doQuery($SQL);	
	
		//closing the transaction
		$this->_DB->getConnection()->commit();

		$this->_DB->doQuery("SELECT * FROM jms_cv where applicantID like '$applicantID'");

		$rows = $this->_DB->getAllRows();

		$row = $rows[0];
		$cvID= $row['ID'];

		for ($i=0; $i < sizeof($CV_Education); $i++) { 
			$Education = $CV_Education[$i];

			$SQL = "INSERT INTO jms_cv_education(cvID,instituition,subject,cgpa)
			 	VALUES('$cvID','".$Education->getinstituition()."','".$Education->getsubject()."','".$Education->getcgpa()."')";

			//echo $SQL; 	

			//beginning a transaction 	
			$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
			//creating the Job
			$SQL = $this->_DB->doQuery($SQL);	
		
			//closing the transaction
			$this->_DB->getConnection()->commit();

		}

		for ($i=0; $i < sizeof($CV_Skills); $i++) { 
			$Skill = $CV_Skills[$i];

			$SQL = "INSERT INTO jms_cv_skills(cvID,name,details)
				 	VALUES('$cvID','".$Skill->getname()."','".$Skill->getdetails()."')";

			//echo $SQL; 	

			//beginning a transaction 	
			$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
			//creating the Job
			$SQL = $this->_DB->doQuery($SQL);	
		
			//closing the transaction
			$this->_DB->getConnection()->commit();
		}

		for ($i=0; $i < sizeof($CV_Experience); $i++) { 
			$Experience = $CV_Experience[$i];

			$SQL = "INSERT INTO jms_cv_experience(cvID,jobname,jobposition,workingyear,workdetails)
				 	VALUES('$cvID','".$Experience->getjobname()."','".$Experience->getjobposition()."','".$Experience->getworkingyear()."','".$Experience->getworkdetails()."')";

			//echo $SQL; 	

			//beginning a transaction 	
			$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
			//creating the Job
			$SQL = $this->_DB->doQuery($SQL);	
		
			//closing the transaction
			$this->_DB->getConnection()->commit();
		}

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("CV Updated Successfully.");
		return $Result;
	}

}
?>