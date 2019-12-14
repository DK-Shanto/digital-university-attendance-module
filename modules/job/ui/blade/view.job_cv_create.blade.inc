<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_JOB.'bao/class.job_cv_create_bao.inc';
include_once MODULES_JOB.'bao/class.job_list_bao.inc';

$_JobCVCreateBAO = new JobCVCreateBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();
$_JobListBAO = new JobListBAO();

/* saving a new job details*/
if(isset($_POST['request']))
{
    $globalUser = '';
    $globalUser = $_SESSION["globalUser"];

    $Result=$_JobListBAO->checkForCV($globalUser);  
    if($Result->getIsSuccess()){
    	$CV = new CV();
    	$CV_Education = new CV_Education();	
    	$CV_Experience = new CV_Experience();		
    	$CV_Skills = new CV_Skills();

    	$globalUser = '';
    	$globalUser = $_SESSION["globalUser"];
    	$Education_List = array();
    	$Experience_List = array();
    	$Skills_List = array();

    	$CV->setapplicantID($globalUser->getID()); 

    	$CV->setsector($_DB->secureInput($_POST['txtCVSector']));

    	$CV->setemail($_DB->secureInput($_POST['txtCVEmail']));

    	$CV->setphone($_DB->secureInput($_POST['txtCVPhone']));

    	$CV->setprofile($_DB->secureInput($_POST['txtCVProfile'])); 

    	$CV->settechnical_skill($_DB->secureInput($_POST['txtCVTechnicalSkills']));

        $skill_number = filter_var( $_DB->secureInput($_POST["skillnumber"]), FILTER_VALIDATE_INT);
        $education_number = filter_var( $_DB->secureInput($_POST["educationnumber"]), FILTER_VALIDATE_INT);
        $experience_number = filter_var( $_DB->secureInput($_POST["experiencenumber"]), FILTER_VALIDATE_INT);


        for($i = 0; $i <= $education_number; $i++) {
            if($_POST['txtCVEducationInstituition_'.$i]<>'' && $_POST['txtCVEducationSubject_'.$i]<>'' && $_POST['txtCVEducationGPA_'.$i]<>''){
                $CV_Education->setinstituition ( $_DB->secureInput($_POST['txtCVEducationInstituition_'.$i]) );   
                $CV_Education->setsubject ( $_DB->secureInput($_POST['txtCVEducationSubject_'.$i]) );
                $CV_Education->setcgpa ( $_DB->secureInput($_POST['txtCVEducationGPA_'.$i]) );

                $Education_List[]=$CV_Education;
            }
        }

        for($i = 0; $i <= $experience_number; $i++) {
            if($_POST['txtCVExperienceName_'.$i]<>'' && $_POST['txtCVExperiencePost_'.$i]<>'' && $_POST['txtCVExperienceTimeSpan_'.$i]<>'' && $_POST['txtCVExperienceDetails_'.$i]<>''){
                $CV_Experience->setjobname ( $_DB->secureInput($_POST['txtCVExperienceName_'.$i]) );   
                $CV_Experience->setjobposition ( $_DB->secureInput($_POST['txtCVExperiencePost_'.$i]) );
                $CV_Experience->setworkingyear ( $_DB->secureInput($_POST['txtCVExperienceTimeSpan_'.$i]) );
                $CV_Experience->setworkdetails ( $_DB->secureInput($_POST['txtCVExperienceDetails_'.$i]) );

                $Experience_List[]=$CV_Experience;
            }
        }

        for($i = 0; $i <= $skill_number; $i++) {
            if($_POST['txtCVSkillHead_'.$i]<>'' && $_POST['txtCVSkillDetails_'.$i]<>''){
                $CV_Skills->setname ( $_DB->secureInput($_POST['txtCVSkillHead_'.$i]) );
                $CV_Skills->setdetails ( $_DB->secureInput($_POST['txtCVSkillDetails_'.$i]) );

                $Skills_List[]=$CV_Skills;
            }
        }

        $CV->seteducation($Education_List);
        $CV->setexperience($Experience_List);
        $CV->setskills($Skills_List);

    	$Result = $_JobCVCreateBAO->newJobCVCreateRequest($CV);		

    	if($Result->getIsSuccess()){
    	   Util::printToast($Result->getResultObject());	
    	}
    }
    else{
        echo '<script type="text/javascript">',
                'alert("Already you have created.To renew please update.");',
            '</script>';
    }
}

/* saving a new job details*/
if(isset($_POST['update']))
{
    $CV = new CV();
    $CV_Education = new CV_Education(); 
    $CV_Experience = new CV_Experience();       
    $CV_Skills = new CV_Skills();

    $globalUser = '';
    $globalUser = $_SESSION["globalUser"];
    $Education_List = array();
    $Experience_List = array();
    $Skills_List = array();

    $CV->setapplicantID($globalUser->getID()); 

    $CV->setID($_DB->secureInput($_POST['txtCVID']));

    $CV->setsector($_DB->secureInput($_POST['txtCVSector']));

    $CV->setemail($_DB->secureInput($_POST['txtCVEmail']));

    $CV->setphone($_DB->secureInput($_POST['txtCVPhone']));

    $CV->setprofile($_DB->secureInput($_POST['txtCVProfile'])); 

    $CV->settechnical_skill($_DB->secureInput($_POST['txtCVTechnicalSkills']));

    $skill_number = filter_var( $_DB->secureInput($_POST["skillnumber"]), FILTER_VALIDATE_INT);
    $education_number = filter_var( $_DB->secureInput($_POST["educationnumber"]), FILTER_VALIDATE_INT);
    $experience_number = filter_var( $_DB->secureInput($_POST["experiencenumber"]), FILTER_VALIDATE_INT);


    for($i = 0; $i < $education_number; $i++) {
        if($_POST['txtCVEducationInstituition_'.$i]<>'' && $_POST['txtCVEducationSubject_'.$i]<>'' && $_POST['txtCVEducationGPA_'.$i]<>''){
            $CV_Education->setinstituition ( $_DB->secureInput($_POST['txtCVEducationInstituition_'.$i]) );   
            $CV_Education->setsubject ( $_DB->secureInput($_POST['txtCVEducationSubject_'.$i]) );
            $CV_Education->setcgpa ( $_DB->secureInput($_POST['txtCVEducationGPA_'.$i]) );

            $Education_List[]=$CV_Education;
        }
    }

    for($i = 0; $i < $experience_number; $i++) {
        if($_POST['txtCVExperienceName_'.$i]<>'' && $_POST['txtCVExperiencePost_'.$i]<>'' && $_POST['txtCVExperienceTimeSpan_'.$i]<>'' && $_POST['txtCVExperienceDetails_'.$i]<>''){
            $CV_Experience->setjobname ( $_DB->secureInput($_POST['txtCVExperienceName_'.$i]) );   
            $CV_Experience->setjobposition ( $_DB->secureInput($_POST['txtCVExperiencePost_'.$i]) );
            $CV_Experience->setworkingyear ( $_DB->secureInput($_POST['txtCVExperienceTimeSpan_'.$i]) );
            $CV_Experience->setworkdetails ( $_DB->secureInput($_POST['txtCVExperienceDetails_'.$i]) );

            $Experience_List[]=$CV_Experience;
        }
    }

    for($i = 0; $i < $skill_number; $i++) {
        if($_POST['txtCVSkillHead_'.$i]<>'' && $_POST['txtCVSkillDetails_'.$i]<>''){
            $CV_Skills->setname ( $_DB->secureInput($_POST['txtCVSkillHead_'.$i]) );
            $CV_Skills->setdetails ( $_DB->secureInput($_POST['txtCVSkillDetails_'.$i]) );

            $Skills_List[]=$CV_Skills;
        }
    }

    $CV->seteducation($Education_List);
    $CV->setexperience($Experience_List);
    $CV->setskills($Skills_List);

    $Result = $_JobCVCreateBAO->JobCVUpdateRequest($CV);     

    if($Result->getIsSuccess()){
       Util::printToast($Result->getResultObject());    
    }
}
?>