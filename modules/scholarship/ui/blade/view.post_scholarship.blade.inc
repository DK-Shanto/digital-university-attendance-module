<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.post_scholarship_bao.inc';
include_once MODULES_SCHOLARSHIP.'bao/class.catagory_bao.inc';

$_ScholarshipBAO = new ScholarshipBAO();
$_CatagoryBAO = new CatagoryBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();

$globalScholarship = '';

// saving a new job details
if(isset($_POST['save']))
{
	$Scholarship = new Scholarship();	

	$Scholarship->setTitle($_DB->secureInput($_POST['txtscholarshipTitle'])); 
	$Scholarship->setSubtitle($_DB->secureInput($_POST['txtScholarshipSubTitle']));
	$Scholarship->setCategory($_DB->secureInput($_POST['selectCatagory']));
	$Scholarship->setOrganization($_DB->secureInput($_POST['txtOrganization']));
	$Scholarship->setGender($_DB->secureInput($_POST['selectGender']));
	$Scholarship->setAgeLimit(strtolower($_DB->secureInput($_POST['txtAge']))); 
	$Scholarship->setEmail(strtolower($_DB->secureInput($_POST['txtEmail'])));
	$Scholarship->setContactNumber($_DB->secureInput($_POST['txtContactNumber'])); 
	$Scholarship->setScholarshipAmount($_DB->secureInput($_POST['txtAmount']));
	$Scholarship->setLastDateOfApplication($_DB->secureInput($_POST['txtLastDateOfApplication'])); 

	$Result = $_ScholarshipBAO->newScholarshipRequest($Scholarship);		

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}
}


//delete a particular scholarship

if(isset($_GET['del'])){
	$Scholarship = new Scholarship();	
	$Scholarship->setID($_GET['del']);	
	$Result = $_ScholarshipBAO->deleteScholarship($Scholarship); //reading the user object from the result object

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}

	//header("Location:".PageUtil::$SCHOLARSHIP_POST);
} 

if(isset($_GET['edit'])){
	$Scholarship = new Scholarship();	
	$Scholarship->setID($_GET['edit']);	

	$globalScholarship = $_ScholarshipBAO->readScholarship($Scholarship)->getResultObject(); 
	//reading the user object from the result object
}


if(isset($_POST['update'])){
	$Scholarship = new Scholarship();

	$Scholarship->setID($_GET['edit']);
	$Scholarship->setTitle($_DB->secureInput($_POST['txtscholarshipTitle'])); 
	$Scholarship->setSubtitle($_DB->secureInput($_POST['txtScholarshipSubTitle']));
	$Scholarship->setCategory($_DB->secureInput($_POST['selectCatagory']));
	$Scholarship->setOrganization($_DB->secureInput($_POST['txtOrganization']));
	$Scholarship->setGender($_DB->secureInput($_POST['selectGender']));
	$Scholarship->setAgeLimit(strtolower($_DB->secureInput($_POST['txtAge']))); 
	$Scholarship->setEmail(strtolower($_DB->secureInput($_POST['txtEmail'])));
	$Scholarship->setContactNumber($_DB->secureInput($_POST['txtContactNumber'])); 
	$Scholarship->setScholarshipAmount($_DB->secureInput($_POST['txtAmount']));
	$Scholarship->setLastDateOfApplication($_DB->secureInput($_POST['txtLastDateOfApplication'])); 

	$Result = $_ScholarshipBAO->updateScholarship($Scholarship);

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}

	header("Location:".PageUtil::$SCHOLARSHIP_POST);
}
?>