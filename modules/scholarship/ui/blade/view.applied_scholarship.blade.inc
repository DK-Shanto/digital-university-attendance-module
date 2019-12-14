<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.applied_scholarship_bao.inc';
include_once MODULES_USER.'bao/class.userbao.inc';



$_AppliedScholarshipBAO = new AppliedScholarshipBAO();
$_ScholarshipBAO = new ScholarshipBAO();
$_StudentHasScholarshipBAO = new StudentHasScholarshipBAO();
$_UserBAO = new UserBAO();
$_StudentBAO = new StudentBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


$globalScholarship = '';
$globalStudentList = '';
  

if(isset($_GET['seemore'])){
	$Scholarship = new Scholarship();
	$Scholarship->setID($_GET['seemore']);
	$globalScholarship = $_ScholarshipBAO->readScholarship($Scholarship)->getResultObject();
}


$globalUser = $_SESSION["globalUser"];
$globalStudent = '';

if(isset($_GET['seecv'])){	
	$Student = new Student();
	$Student->setUniversityID($_GET['seecv']); 
	$Result = $_StudentBAO->readStudentByUniversityID($Student)->getResultObject();

	$globalStudent = $Result;

   $User = new User();	
   $User->setUniversityID($_GET['seecv']);

   $userPositions = $_UserBAO->readUser_By_UniversityID($User)->getResultObject(); 
   $userDetails = $_UserBAO->readUserDetailsByUniversityID($User)->getResultObject();
}


if(isset($_POST['updatePriority'])){
	$Scholarship = new Scholarship();
	$Scholarship->setID($_GET['us']);
	$globalScholarship = $_ScholarshipBAO->readScholarship($Scholarship)->getResultObject();

	$StudentHasScholarship = new StudentHasScholarship();

	$StudentHasScholarship->setScholarshipID($_GET['us']);
	$StudentHasScholarship->setUniversityID($_GET['uu']);
	$StudentHasScholarship->setPriority($_DB->secureInput($_POST['txtPriority'])); 
	

	$Result = $_StudentHasScholarshipBAO->updateStudentHasScholarshipPriority($StudentHasScholarship);

	

	//header("Location:".PageUtil::$SCHOLARSHIP_POST);
}

if(isset($_GET['approveu']) && isset($_GET['approves'])){
	$Scholarship = new Scholarship();
	$Scholarship->setID($_GET['approves']);
	$globalScholarship = $_ScholarshipBAO->readScholarship($Scholarship)->getResultObject();

	$StudentHasScholarship = new StudentHasScholarship();

	$StudentHasScholarship->setScholarshipID($_GET['approves']);
	$StudentHasScholarship->setUniversityID($_GET['approveu']);
	$StudentHasScholarship->setStatus("approved"); 
	

	$Result = $_StudentHasScholarshipBAO->updateStudentHasScholarshipStatus($StudentHasScholarship);

	

	//header("Location:".PageUtil::$SCHOLARSHIP_POST);
}

if(isset($_GET['rejectu']) && isset($_GET['rejects'])){
	$Scholarship = new Scholarship();
	$Scholarship->setID($_GET['rejects']);
	$globalScholarship = $_ScholarshipBAO->readScholarship($Scholarship)->getResultObject();

	$StudentHasScholarship = new StudentHasScholarship();

	$StudentHasScholarship->setScholarshipID($_GET['rejects']);
	$StudentHasScholarship->setUniversityID($_GET['rejectu']);
	$StudentHasScholarship->setStatus("rejected");
	

	$Result = $_StudentHasScholarshipBAO->updateStudentHasScholarshipStatus($StudentHasScholarship);

	

	//header("Location:".PageUtil::$SCHOLARSHIP_POST);
}

?>