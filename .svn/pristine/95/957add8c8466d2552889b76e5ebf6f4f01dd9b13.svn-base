<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.scholarship.inc';
include_once COMMON.'class.common.user.inc';

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

		$SQL = "UPDATE sms_scholarship_student SET 
			age='$Age', fProf='$FatherProf', mProf='$MotherProf', income='$Income', sibling='$Sibling', reason='$Reason', cocurricular='$Cocurricular', quota='$Quota', term='$CurrentTerm', cgpa='$Cgpa', picSource='$PicSource', document='$Document'  WHERE universityId='$UniversityID'";

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