

<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.scholarship.inc';
include_once COMMON.'class.common.user.inc';

Class AppliedScholarshipDAO{
	private $_DB;
	private $_AppliedScholarship;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_AppliedScholarship = new AppliedScholarship();
	}

	// get all the AppliedScholarships from the database using the database query
	public function getAllAppliedScholarships(){

		$AppliedScholarshipList = array();

		// $this->_DB->doQuery("SELECT * FROM ums_user where IsDeleted is null 
		// 	order by (UniversityID * 1) ASC");
		$this->_DB->doQuery("SELECT s.id,s.title,s.category,s.lastDate,r.numOfStudents FROM sms_scholarship as s join (SELECT scholarshipId as id, count(studentId) as numOfStudents FROM sms_scholarship_applyscholarship as a GROUP BY scholarshipId) as r ON r.id = s.id");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_AppliedScholarship = new AppliedScholarship();

			$this->_AppliedScholarship->setID ( $row['id']);
		    $this->_AppliedScholarship->setTitle ( $row['title']); 
		    $this->_AppliedScholarship->setCategory ( $row['category'] );
		    $this->_AppliedScholarship->setLastDateOfApplication( $row['lastDate'] );
		    $this->_AppliedScholarship->setNumOfStudents ( $row['numOfStudents'] );
		    $AppliedScholarshipList[]=$this->_AppliedScholarship;
   
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($AppliedScholarshipList);

		return $Result;
	}
}


Class ScholarshipDAO{
	private $_DB;
	private $_Scholarship;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Scholarship = new Scholarship();
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

Class StudentHasScholarshipDAO{
	private $_DB;
	private $_StudentHasScholarship;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_StudentHasScholarship = new StudentHasScholarship();
	}

	

	//create new job request with the job object
	public function getStudentHasScholarshipByScholarshipID($Scholarship){

	    $StudentHasScholarshipList = array();


		$SQL = "SELECT * from sms_scholarship_applyscholarship 
		where scholarshipId ='".$Scholarship->getID()."'";

		$rows = $this->_DB->getAllRows();

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

	public function getAllStudentsByScholarshipId($Scholarship){

		$StudentList = array();

		$this->_DB->doQuery("SELECT * FROM (SELECT * FROM sms_scholarship_applyscholarship as ssa JOIN sms_scholarship_student as sss ON ssa.studentId = sss.universityId)as a join (SELECT u.UniversityID, u.Email, u.FirstName, u.MiddleName, u.LastName, ud.FatherName, ud.MotherName, ud.PermanentAddress, ud.HomePhone, ud.CurrentAddress, ud.MobilePhone, d.ShortCode as discipline FROM ums_user as u JOIN ums_user_details as ud join ums_discipline as d ON u.DisciplineID=d.ID AND u.ID = ud.ID) as s ON a.studentId = s.UniversityId where a.scholarshipId='".$Scholarship->getID()."'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Student = new Student();

			$this->_Student->setUniversityID ( $row['studentId']);
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

		    $StudentList[]=$this->_Student;
   
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($StudentList);

		return $Result;
	}

	public function getAllUsersByScholarshipId($Scholarship){

		$UserList = array();

		$this->_DB->doQuery("SELECT * FROM (SELECT * FROM sms_scholarship_applyscholarship as ssa JOIN sms_scholarship_student as sss ON ssa.studentId = sss.universityId)as a join (SELECT u.UniversityID, u.Email, u.FirstName, u.MiddleName, u.LastName, ud.FatherName, ud.MotherName, ud.PermanentAddress, ud.HomePhone, ud.CurrentAddress, ud.MobilePhone, d.ShortCode as discipline FROM ums_user as u JOIN ums_user_details as ud join ums_discipline as d ON u.DisciplineID=d.ID AND u.ID = ud.ID) as s ON a.studentId = s.UniversityId where a.scholarshipId='".$Scholarship->getID()."'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_User = new User();

			$this->_User->setUniversityID ( $row['studentId']);
		    $this->_User->setEmail ( $row['Email']);
		    $this->_User->setFirstName ( $row['FirstName'] );   
		    $this->_User->setMiddleName ( $row['MiddleName'] );
		    $this->_User->setLastName ( $row['LastName'] );
		    $this->_User->setDiscipline ( $row['discipline'] );
		    $this->_User->setStatus ( $row['status'] );
		    $this->_User->setPriority ( $row['priority'] );
		    //$this->_User->setStatus( $row['reason'] );
		    
		    $UserList[]=$this->_User;
   
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($UserList);

		return $Result;
	}

	//update an Student object based on its id information
	public function updateStudentHasScholarshipPriority($StudentHasScholarship){

		$ScholarshipId = $StudentHasScholarship->getScholarshipID();
		$StudentId = $StudentHasScholarship->getUniversityID();
		$Priority = $StudentHasScholarship->getPriority();
		


		$SQL = "UPDATE sms_scholarship_applyscholarship SET 
			priority='$Priority' WHERE scholarshipId='$ScholarshipId' and studentId='$StudentId'";

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//updating the user
		$SQL = $this->_DB->doQuery($SQL);
				
		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Priority updated Successfully");

		return $Result;

	}

	//update an Student object based on its id information
	public function updateStudentHasScholarshipStatus($StudentHasScholarship){

		$ScholarshipId = $StudentHasScholarship->getScholarshipID();
		$StudentId = $StudentHasScholarship->getUniversityID();
		$Status = $StudentHasScholarship->getStatus();
		


		$SQL = "UPDATE sms_scholarship_applyscholarship SET 
			status='$Status' WHERE scholarshipId='$ScholarshipId' and studentId='$StudentId'";

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//updating the user
		$SQL = $this->_DB->doQuery($SQL);
				
		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Student has approved for this Scholarship Successfully");

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
	    $PicSource = $Student->getPicSource();
	    $Document = $Student->getDocument();


		$SQL = "INSERT INTO sms_scholarship_student(universityId, age, fProf, mProf, income, sibling, reason, cocurricular, quota, term, cgpa, picSource, document)

		 	VALUES('$UniversityID','$Age','$FatherProf','$MotherProf','$Income','$Sibling','$Reason','$Cocurricular','$Quota','$CurrentTerm','$Cgpa', '$PicSource', '$Document')";

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


	//delete an user based on its id of the database
	public function deleteStudent($Student){

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
	
		//removing previous Positions 

		$SQL_delete = "DELETE from sms_Student where id ='".$Student->getUniversityID()."'";
		$SQL_delete = $this->_DB->doQuery($SQL_delete);


		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Student Deleted Successfully.");

		return $Result;

	}


	public function readStudentByUniversityID($Student){

		$SQL = "SELECT * from sms_scholarship_student 
			where universityId ='".$Student->getUniversityID()."'";

		$this->_DB->doQuery($SQL);

		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		if(sizeof($row)>0){

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
	    $this->_Student->setPicSource( $row['picSource'] );
	    $this->_Student->setDocument( $row['document'] );


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


	//update an Student object based on its id information
	public function updateStudent($Student){

		$ID = $Student->getID();
		$Title=$Student->getTitle();
		$Subtitle=$Student->getSubtitle();
		$Category=$Student->getCategory();
		$PublishDate=date("Y-m-d");
		$Organization=$Student->getOrganization();
		$Gender=$Student->getGender();
		$AgeLimit = $Student->getAgeLimit();
		$Email=$Student->getEmail();
		$ContactNumber = $Student->getContactNumber();	
		$Amount=$Student->getStudentAmount();
		$LastDateOfApplication = $Student->getLastDateOfApplication();	


		$SQL = "UPDATE sms_Student SET 
			title='$Title', subTitle='$Subtitle', category='$Category', publishDate='$PublishDate', organization='$Organization', gender='$Gender', ageLimit='$AgeLimit', email='$Email', contact='$ContactNumber', amount='$Amount', lastDate='$LastDateOfApplication' WHERE id='$ID'";

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//updating the user
		$SQL = $this->_DB->doQuery($SQL);
				
		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Student updated Successfully");

		return $Result;

	}
}

?>


