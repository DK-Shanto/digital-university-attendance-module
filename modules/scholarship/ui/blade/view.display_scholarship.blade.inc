<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.display_scholarship_bao.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.quota_bao.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.cocurricular_bao.inc';
include_once MODULES_USER.'bao/class.userbao.inc';

$_ScholarshipBAO = new ScholarshipBAO();
$_UserBAO = new UserBAO();
$_QuotaBAO = new QuotaBAO();
$_CocurricularBAO = new CocurricularBAO();
$_StudentBAO = new StudentBAO();
$_StudentHasScholarshipBAO = new StudentHasScholarshipBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


$globalUser = $_SESSION["globalUser"];
$flag = false;
$temp1 = false;

$User = new User();	
$User->setUniversityID($globalUser->getUniversityID());

$Result = $_StudentHasScholarshipBAO->getStudentHasScholarshipByUniversityID($User)->getResultObject();

if($Result!="null"){
	$StudentHasScholarshipList = $Result;
	$temp1 = true;
}

$globalScholarship = '';




if(isset($_GET['apply'])){
	
		$User = new User();	
		$User->setID($globalUser->getID());

		$userPositions = $_UserBAO->readUser($User)->getResultObject(); 
		$userDetails = $_UserBAO->readUserDetails($User)->getResultObject(); 

		$Scholarship = new Scholarship();
		$Scholarship->setID($_GET['apply']);
		$globalScholarship = $_ScholarshipBAO->readScholarship($Scholarship)->getResultObject();
		//reading the user object from the result object
		$flag=false;
		$Student = new Student();
		$Student->setUniversityID($globalUser->getUniversityID()); 
		$Result = $_StudentBAO->readStudentByUniversityID($Student)->getResultObject();
		

		if($Result != "null"){
			   $globalStudent = $Result;
			   $flag= true;	
		}
	
}

if(isset($_POST['save'])){

	$StudentHasScholarship = new StudentHasScholarship();
	$StudentHasScholarship->setUniversityID($globalUser->getUniversityID()); 
	$StudentHasScholarship->setScholarshipID($globalScholarship->getID());
	$StudentHasScholarship->setStatus("pending");
	

	$Result = $_StudentHasScholarshipBAO->newStudentHasScholarshipRequest($StudentHasScholarship);

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}

	header("Location:".PageUtil::$SCHOLARSHIP_VIEW);


}




?>