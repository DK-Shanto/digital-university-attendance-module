<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.upload_cv_bao.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.quota_bao.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.cocurricular_bao.inc';
include_once MODULES_USER.'bao/class.userbao.inc';

$_UserBAO = new UserBAO();
$_QuotaBAO = new QuotaBAO();
$_CocurricularBAO = new CocurricularBAO();
$_StudentBAO = new StudentBAO();

$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


$globalUser = $_SESSION["globalUser"];
$globalStudent = '';



$Student = new Student();
$Student->setUniversityID($globalUser->getUniversityID()); 
$Result = $_StudentBAO->readStudentByUniversityID($Student)->getResultObject();
$flag = false;

if($Result != "null"){
	   $globalStudent = $Result;
	   $flag= true;	

	   $User = new User();	
	   $User->setID($globalUser->getID());

	   $userPositions = $_UserBAO->readUser($User)->getResultObject(); 
       $userDetails = $_UserBAO->readUserDetails($User)->getResultObject();
	}





if(isset($_GET['apply'])){

	$User = new User();	
	$User->setID($globalUser->getID());

	$userPositions = $_UserBAO->readUser($User)->getResultObject(); 
	$userDetails = $_UserBAO->readUserDetails($User)->getResultObject(); 

	//reading the user object from the result object
}

if(isset($_POST['save'])){

	$Student = new Student();	

	$Student->setUniversityID($globalUser->getUniversityID()); 
	$Student->setAge($_DB->secureInput($_POST['txtAge']));
	$Student->setFatherProf($_DB->secureInput($_POST['txtFatherProf']));
	$Student->setMotherProf($_DB->secureInput($_POST['txtMotherProf']));
	$Student->setIncome($_DB->secureInput($_POST['txtIncome']));
	$Student->setSibling(strtolower($_DB->secureInput($_POST['selectSibling'])));
	$Student->setReason(strtolower($_DB->secureInput($_POST['txtReason'])));
	
	if(isset($_POST['selectCocurricular'])){ 
		$Student->setCocurricular($_DB->secureInput($_POST['selectCocurricular']));
	}
	 
	if(isset($_POST['selectQuota'])){ 
		$Student->setQuota($_DB->secureInput($_POST['selectQuota']));
	} 
	
	$Student->setCurrentTerm($_DB->secureInput($_POST['selectTerm']));
	$Student->setCgpa($_DB->secureInput($_POST['txtCgpa']));

	if(isset($_FILES['uploadImage'])){
		$imageName = $_FILES['uploadImage']['name'];
		$tempName = $_FILES['uploadImage']['tmp_name'];
		$folder = RESOURCES.'img/scholarship/images/'.$imageName;

		$Student->setPicSource($_DB->secureInput($imageName));
		move_uploaded_file($tempName, $folder);		
	}
		
	
	if(isset($_FILES['uploadFile'])){ 
		$fileName = $_FILES['uploadFile']['name'];
		$tempName = $_FILES['uploadFile']['tmp_name'];
		$folder = RESOURCES.'img/scholarship/documents/'.$fileName;

		$Student->setDocument($_DB->secureInput($fileName));
		move_uploaded_file($tempName, $folder); 
	} 

	$Result = $_StudentBAO->newStudentRequest($Student);		

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}

	header("Location:".PageUtil::$SCHOLARSHIP_VIEW);


}


if(isset($_POST['update'])){

	$Student = new Student();	

	$Student->setUniversityID($globalUser->getUniversityID()); 
	$Student->setAge($_DB->secureInput($_POST['txtAge']));
	$Student->setFatherProf($_DB->secureInput($_POST['txtFatherProf']));
	$Student->setMotherProf($_DB->secureInput($_POST['txtMotherProf']));
	$Student->setIncome($_DB->secureInput($_POST['txtIncome']));
	$Student->setSibling(strtolower($_DB->secureInput($_POST['selectSibling'])));
	$Student->setReason(strtolower($_DB->secureInput($_POST['txtReason'])));
	
	if(isset($_POST['selectCocurricular'])){ 
		$Student->setCocurricular($_DB->secureInput($_POST['selectCocurricular']));
	}
	 
	if(isset($_POST['selectQuota'])){ 
		$Student->setQuota($_DB->secureInput($_POST['selectQuota']));
	} 
	
	$Student->setCurrentTerm($_DB->secureInput($_POST['selectTerm']));
	$Student->setCgpa($_DB->secureInput($_POST['txtCgpa']));

	if(isset($_FILES['uploadImage'])){
		$imageName = $_FILES['uploadImage']['name'];
		$tempName = $_FILES['uploadImage']['tmp_name'];
		$folder = RESOURCES.'img/scholarship/images/'.$imageName;

		$Student->setPicSource($_DB->secureInput($imageName));
		move_uploaded_file($tempName, $folder);		
	}
		
	
	if(isset($_FILES['uploadFile'])){ 
		$fileName = $_FILES['uploadFile']['name'];
		$tempName = $_FILES['uploadFile']['tmp_name'];
		$folder = RESOURCES.'img/scholarship/documents/'.$fileName;

		$Student->setDocument($_DB->secureInput($fileName));
		move_uploaded_file($tempName, $folder); 
	} 

	$Result = $_StudentBAO->updateStudent($Student);		

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}

	header("Location:".PageUtil::$SCHOLARSHIP_VIEW);


}

?>