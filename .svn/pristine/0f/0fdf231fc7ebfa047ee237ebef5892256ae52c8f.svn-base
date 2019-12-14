<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_JOB.'bao/class.job_list_bao.inc';


$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();
$_JobListBAO = new JobListBAO();

// editing a job information
if(isset($_GET['edit']))
{
	$Job = new Job();	
	$Job->setID($_GET['edit']);	
	$globalJob = $_JobListBAO->readJobPositions($Job)->getResultObject(); 
}
/* deleting an existing Job information */
if(isset($_GET['del']))
{

	$Job = new Job();	
	$Job->setID($_GET['del']);	
	$_JobListBAO->deleteJob($Job); //reading the user object from the result object

	header("Location:".PageUtil::$JOB_UPDATE);
}
/*updating an existing job information*/
if(isset($_POST['update']))
{
	$Job = new Job();

	$Job->setID($_GET['edit']);		

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

	$_JobListBAO->updateJobRequest($Job);

	header("Location:".PageUtil::$JOB_UPDATE);
}
//appling for a job
if(isset($_GET['apply']))
{
	$globalUser = '';
	$globalUser = $_SESSION["globalUser"];

	$Result=$_JobListBAO->checkForCV($globalUser);	
	if($Result->getIsSuccess()){

		$Applicant = new Applicant();

		$Applicant->setapplicantID($globalUser->getID());
		$Applicant->setJobID($_GET['apply']);
		$Applicant->setcvID($Result->getResultObject());

		$datetime = new DateTime('now', new DateTimezone('Asia/Dhaka'));
		$Applicant->setSubmissionDate($datetime->format('Y-m-d h:i:s'));

		$Result_new=$_JobListBAO->applyJob($Applicant); //reading the job object from the result object
		if($Result_new->getIsSuccess()){
			echo '<script type="text/javascript">',
     				'alert("'.$Result_new->getResultObject().'");',
     			'</script>';
		}
		else{
			echo '<script type="text/javascript">',
     				'alert("Please Try again later.");',
     			'</script>';
		} 
	}
	else{
		echo '<script type="text/javascript">',
     			'alert("Please Create a CV First.");',
     		'</script>';
	}
}
?>