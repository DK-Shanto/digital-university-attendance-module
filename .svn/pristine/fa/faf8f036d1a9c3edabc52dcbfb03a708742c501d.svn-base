<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.scholarship.inc';
include_once COMMON.'class.common.user.inc';

Class ScholarshipDAO{
	private $_DB;
	private $_Scholarship;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Scholarship = new Scholarship();
	}

	// get all the scholarships from the database using the database query
	public function getAllScholarships(){

		$ScholarshipList = array();

		// $this->_DB->doQuery("SELECT * FROM ums_user where IsDeleted is null 
		// 	order by (UniversityID * 1) ASC");
		$this->_DB->doQuery("SELECT * FROM sms_scholarship
			order by (id * 1) ASC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Scholarship = new Scholarship();

			$this->_Scholarship->setID ( $row['id']);
		    $this->_Scholarship->setTitle ( $row['title']);
		    $this->_Scholarship->setSubtitle ( $row['subTitle'] );   
		    $this->_Scholarship->setCategory ( $row['category'] );
		    $this->_Scholarship->setOrganization ( $row['organization'] );
		    $this->_Scholarship->setPublishDate ( $row['publishDate'] );
		    $this->_Scholarship->setGender( $row['gender'] );
		    $this->_Scholarship->setAgeLimit( $row['ageLimit'] );
		    $this->_Scholarship->setEmail( $row['email'] );
		    $this->_Scholarship->setContactNumber( $row['contact'] );
		    $this->_Scholarship->setScholarshipAmount( $row['amount'] );
		    $this->_Scholarship->setLastDateOfApplication( $row['lastDate'] );

		    $ScholarshipList[]=$this->_Scholarship;
   
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($ScholarshipList);

		return $Result;
	}


	public function readScholarship($Scholarship){

		$SQL = "SELECT * from sms_scholarship where id ='".$Scholarship->getID()."'";

		$this->_DB->doQuery($SQL);

		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		$this->_Scholarship = new Scholarship();

		$this->_Scholarship->setID ( $row['id']);
	    $this->_Scholarship->setTitle ( $row['title']);
	    $this->_Scholarship->setSubtitle ( $row['subTitle'] );   
	    $this->_Scholarship->setCategory ( $row['category'] );
	    $this->_Scholarship->setOrganization ( $row['organization'] );
	    $this->_Scholarship->setPublishDate ( $row['publishDate'] );
	    $this->_Scholarship->setGender( $row['gender'] );
	    $this->_Scholarship->setAgeLimit( $row['ageLimit'] );
	    $this->_Scholarship->setEmail( $row['email'] );
	    $this->_Scholarship->setContactNumber( $row['contact'] );
	    $this->_Scholarship->setScholarshipAmount( $row['amount'] );
	    $this->_Scholarship->setLastDateOfApplication( $row['lastDate'] );


	    $Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Scholarship);

		return $Result;
	}

}


Class StudentDAO{
	private $_DB;
	private $_Student;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Student = new Student();
	}

	//create new job request with the job object
	public function newStudentRequest($Student){

		$UniversityID = $Student->getUniversityID();
	    $Age = $Student->getAge();
	    $FatherProf = $Student->getFatherProf();
	    $MotherProf = $Student->getMotherProf();
	    $Income = $Student->getIncome();
	    $Sibling = $Student->getSibling();
	    $Reason = $Student->getReason();
	    $Cocurricular = $Student->getCocurricular();
	    $Quota = $Student->getQuota();
	    $CurrentTerm = $Student->getCurrentTerm();
	    $Cgpa = $Student->getCgpa();
	    //$PicSource = $Student->getPicSource();


		$SQL = "INSERT INTO sms_scholarship_student(universityId, age, fProf, mProf, income, sibling, reason, cocurricular, quota, term, cgpa)

		 	VALUES('$UniversityID','$Age','$FatherProf','$MotherProf','$Income','$Sibling','$Reason','$Cocurricular','$Quota','$CurrentTerm','$Cgpa')";

		//echo $SQL; 	

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the Job
		$SQL = $this->_DB->doQuery($SQL);	
	
		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("New Student Request Submitted Successfully.");

		return $Result;
	}


	public function readStudentByUniversityID($Student){

		$SQL = "SELECT * from sms_scholarship_student 
			where universityId ='".$Student->getUniversityID()."'";

		$this->_DB->doQuery($SQL);

		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		if($row != null){

		$this->_Student = new Student();


		$this->_Student->setUniversityID ( $row['universityId']);
	    $this->_Student->setAge ( $row['age']);
	    $this->_Student->setFatherProf ( $row['fProf'] );   
	    $this->_Student->setMotherProf ( $row['mProf'] );
	    $this->_Student->setIncome ( $row['income'] );
	    $this->_Student->setSibling ( $row['sibling'] );
	    $this->_Student->setReason( $row['reason'] );
	    $this->_Student->setCocurricular( $row['cocurricular'] );
	    $this->_Student->setQuota( $row['quota'] );
	    $this->_Student->setCurrentTerm( $row['term'] );
	    $this->_Student->setCgpa( $row['cgpa'] );
	    //$this->_Student->setFileSource( $row['lastDate'] );


	    $Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Student);

		}
		else{
			$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject("null");
		}

		return $Result;
	}
}


Class StudentHasScholarshipDAO{
	private $_DB;
	private $_StudentHasScholarship;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_StudentHasScholarship = new StudentHasScholarship();
	}

	//create new job request with the job object
	public function newStudentHasScholarshipRequest($StudentHasScholarship){

		$UniversityID = $StudentHasScholarship->getUniversityID();
	    $ScholarshipID = $StudentHasScholarship->getScholarshipID();
	    $Status = $StudentHasScholarship->getStatus();
	    //$Priority = $StudentHasScholarship->getPriority();


		$SQL = "INSERT INTO sms_scholarship_applyscholarship (studentId, scholarshipId, status)

		 	VALUES('$UniversityID','$ScholarshipID', '$Status')";

		//echo $SQL; 	

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the Job
		$SQL = $this->_DB->doQuery($SQL);	
	
		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("New StudentHasScholarship Request Submitted Successfully.");

		return $Result;
	}

	// get all the AppliedScholarships from the database using the database query
	public function readStudentHasScholarship($StudentHasScholarship){

		$ScholarshipId = $StudentHasScholarship->getScholarshipID();
		$StudentId = $StudentHasScholarship->getUniversityID();

		// $this->_DB->doQuery("SELECT * FROM ums_user where IsDeleted is null 
		// 	order by (UniversityID * 1) ASC");
		$this->_DB->doQuery("SELECT * FROM sms_scholarship_applyscholarship where scholarshipId='$ScholarshipId' and studentId='$StudentId'");

		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		if(sizeof($row)>0){

		$this->_StudentHasScholarship = new StudentHasScholarship();


		$this->_StudentHasScholarship->setUniversityID ( $row['studentId']);
	    $this->_StudentHasScholarship->setScholarshipID ( $row['scholarshipId']);
	    //$this->_StudentHasScholarship->setFatherProf ( $row['fProf'] );   
	    

	    $Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_StudentHasScholarship);

		}
		else{
			$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject("null");
		}

		return $Result;
	}

	//create new job request with the job object
	public function getStudentHasScholarshipByUniversityID($User){

	    $StudentHasScholarshipList = array();

	    $StudentID = $User->getUniversityID();

	    $this->_DB->doQuery("SELECT * from sms_scholarship_applyscholarship where studentId='$StudentID'");

		$rows = $this->_DB->getAllRows();

		if(sizeof($rows)>0){

			for($i = 0; $i < sizeof($rows); $i++) {
				$row = $rows[$i];
				$this->_StudentHasScholarship = new StudentHasScholarship();

				$this->_StudentHasScholarship->setUniversityID ( $row['studentId']);
			    $this->_StudentHasScholarship->setScholarshipID ( $row['scholarshipId']);

			    $StudentHasScholarshipList[]=$this->_StudentHasScholarship;
	   
			}


			$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject($StudentHasScholarshipList);

			return $Result;
		}
		else{
			$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject("null");

			return $Result;
		}
	}
}

?>
