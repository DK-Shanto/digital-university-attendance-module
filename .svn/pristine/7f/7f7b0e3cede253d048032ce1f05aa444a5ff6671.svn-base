<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_JOB.'bao/class.job_post_bao.inc';

$_JobBAO = new JobBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();

/* saving a new job details*/
if(isset($_POST['request']))
{
	$Job = new Job();	

	$Job->setTitle($_DB->secureInput($_POST['txtJobTitle'])); 

	$Job->setSubtitle($_DB->secureInput($_POST['txtJobSubTitle']));

	$Job->setOrganization($_DB->secureInput($_POST['txtOrganization']));

	$Job->setQualification($_DB->secureInput($_POST['txtQualification']));

	$Job->setGender($_DB->secureInput($_POST['selectGender']));

	$Job->setAgeLimit(strtolower($_DB->secureInput($_POST['txtAge']))); 

	$Job->setEmploymentType($_DB->secureInput($_POST['selectEmploymentType']));

	$Job->setNumberOfVacancy($_DB->secureInput($_POST['txtVacancy']));

	$Job->setEmail(strtolower($_DB->secureInput($_POST['txtEmail'])));

	$Job->setContactNumber($_DB->secureInput($_POST['txtContactNumber'])); 

	$Job->setSalary($_DB->secureInput($_POST['txtSalary']));

	$Job->setLocation($_DB->secureInput($_POST['txtLocation']));

	$Job->setJobExperience($_DB->secureInput($_POST['txtJobExperience']));

	$Job->setLastDateOfApplication($_DB->secureInput($_POST['txtLastDateOfApplication'])); 

	$Result = $_JobBAO->newJobRequest($Job);		

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}
}
?>