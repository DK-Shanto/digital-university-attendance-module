<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.achieved_scholarship_bao.inc';
include_once MODULES_USER.'bao/class.userbao.inc';


$_ScholarshipBAO = new ScholarshipBAO();
$_StudentHasScholarshipBAO = new StudentHasScholarshipBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


$globalUser = $_SESSION["globalUser"];
$flag = false;

$User = new User();	
$User->setUniversityID($globalUser->getUniversityID());

$StudentHasScholarshipList = $_StudentHasScholarshipBAO->getStudentHasScholarshipByUniversityID($User)->getResultObject();
//var_dump($Result);

if($StudentHasScholarshipList!="null"){
	   $flag = true;
	}


?>