<?php 
class Job{
    
    private $_ID;
    private $_Title;
    private $_Subtitle;
    private $_PublishDate;
    private $_Organization;
    private $_Qualification;
    private $_Gender;
    private $_AgeLimit;
    private $_EmploymentType;
    private $_NumberOfVacancy;
    private $_Email;
    private $_ContactNumber;
    private $_Salary;
    private $_Location;
    private $_JobExperience;
    private $_LastDateOfApplication;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setTitle( $Title ) {
        $this->_Title = $Title;
    }

    public function getTitle() {
        return $this->_Title;
    }

    public function setSubtitle ( $Subtitle ) {
        $this->_Subtitle = $Subtitle;
    }

    public function getSubtitle () {
        return $this->_Subtitle;
    }

    public function setPublishDate ( $PublishDate ) {
        $this->_PublishDate = $PublishDate;
    }

    public function getPublishDate () {
        return $this->_PublishDate;
    }

    public function setOrganization ( $Organization ) {
        $this->_Organization = $Organization;
    }

    public function getOrganization () {
        return $this->_Organization;
    }

    public function setQualification ( $Qualification ) {
        $this->_Qualification = $Qualification;
    }

    public function getQualification () {
        return $this->_Qualification;
    }

    public function setGender ( $Gender ) {
        $this->_Gender = $Gender;
    }

    public function getGender () {
        return $this->_Gender;
    }


    public function setAgeLimit( $AgeLimit ) {
        $this->_AgeLimit = $AgeLimit;
    }

    public function getAgeLimit() {
        return $this->_AgeLimit;
    }

    public function setEmploymentType ( $EmploymentType ) {
        $this->_EmploymentType = $EmploymentType;
    }

    public function getEmploymentType () {
        return $this->_EmploymentType;
    }

    public function setNumberOfVacancy ( $NumberOfVacancy ) {
        $this->_NumberOfVacancy = $NumberOfVacancy;
    }

    public function getNumberOfVacancy () {
        return $this->_NumberOfVacancy;
    }

    public function setEmail ( $Email ) {
        $this->_Email = $Email;
    }

    public function getEmail () {
        return $this->_Email;
    }

    public function setContactNumber ( $ContactNumber ) {
        $this->_ContactNumber = $ContactNumber;
    }

    public function getContactNumber () {
        return $this->_ContactNumber;
    }

    public function setSalary ( $Salary ) {
        $this->_Salary = $Salary;
    }

    public function getSalary () {
        return $this->_Salary;
    }


    public function setLocation( $Location ) {
        $this->_Location = $Location;
    }

    public function getLocation() {
        return $this->_Location;
    }

    public function setJobExperience ( $JobExperience ) {
        $this->_JobExperience = $JobExperience;
    }

    public function getJobExperience () {
        return $this->_JobExperience;
    }

    public function setLastDateOfApplication ( $LastDateOfApplication ) {
        $this->_LastDateOfApplication = $LastDateOfApplication;
    }

    public function getLastDateOfApplication () {
        return $this->_LastDateOfApplication;
    }
    
}

class Applicant{
    private $_ID;
    private $_applicantID;
    private $_JobID;
    private $_cvID;
    private $_SubmissionDate;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setapplicantID( $applicantID ) {
        $this->_applicantID = $applicantID;
    }

    public function getapplicantID () {
        return $this->_applicantID;
    }

    public function setJobID ( $JobID ) {
        $this->_JobID = $JobID;
    }

    public function getJobID () {
        return $this->_JobID;
    }

    public function setcvID ( $cvID ) {
        $this->_cvID = $cvID;
    }

    public function getcvID () {
        return $this->_cvID;
    }

    public function setSubmissionDate( $SubmissionDate) {
        $this->_SubmissionDate= $SubmissionDate;
    }

    public function getSubmissionDate() {
        return $this->_SubmissionDate;
    }
}
class CV{
    private $_ID;
    private $_applicantID;
    private $_Name;
    private $_sector;
    private $_email;
    private $_phone;
    private $_profile;
    private $_technical_skill;
    private $_education;
    private $_skills;
    private $_experience;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setapplicantID( $applicantID ) {
        $this->_applicantID = $applicantID;
    }

    public function getapplicantID () {
        return $this->_applicantID;
    }

    public function setName ( $Name ) {
        $this->_Name = $Name;
    }

    public function getName () {
        return $this->_Name;
    }

    public function setsector ( $sector ) {
        $this->_sector = $sector;
    }

    public function getsector () {
        return $this->_sector;
    }

    public function setemail( $email) {
        $this->_email= $email;
    }

    public function getemail() {
        return $this->_email;
    }

    public function setphone ( $phone ) {
        $this->_phone = $phone;
    }

    public function getphone () {
        return $this->_phone;
    }

    public function setprofile ( $profile ) {
        $this->_profile = $profile;
    }

    public function getprofile () {
        return $this->_profile;
    }

    public function settechnical_skill( $technical_skill) {
        $this->_technical_skill= $technical_skill;
    }

    public function gettechnical_skill() {
        return $this->_technical_skill;
    }

    public function seteducation ( $education ) {
        $this->_education = $education;
    }

    public function geteducation () {
        return $this->_education;
    }

    public function setskills ( $skills ) {
        $this->_skills = $skills;
    }

    public function getskills () {
        return $this->_skills;
    }

    public function setexperience( $experience) {
        $this->_experience= $experience;
    }

    public function getexperience() {
        return $this->_experience;
    }
}
class CV_Education{
    private $_ID;
    private $_cvID;
    private $_instituition;
    private $_subject;
    private $_cgpa;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setcvID ( $cvID ) {
        $this->_cvID = $cvID;
    }

    public function getcvID () {
        return $this->_cvID;
    }

    public function setinstituition( $instituition ) {
        $this->_instituition = $instituition;
    }

    public function getinstituition () {
        return $this->_instituition;
    }

    public function setsubject ( $subject ) {
        $this->_subject = $subject;
    }

    public function getsubject () {
        return $this->_subject;
    }

    public function setcgpa ( $cgpa ) {
        $this->_cgpa = $cgpa;
    }

    public function getcgpa () {
        return $this->_cgpa;
    }
}
class CV_Experience{
    private $_ID;
    private $_cvID;
    private $_jobname;
    private $_jobposition;
    private $_workingyear;
    private $_workdetails;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setcvID ( $cvID ) {
        $this->_cvID = $cvID;
    }

    public function getcvID () {
        return $this->_cvID;
    }

    public function setjobname( $jobname ) {
        $this->_jobname = $jobname;
    }

    public function getjobname () {
        return $this->_jobname;
    }

    public function setjobposition ( $jobposition ) {
        $this->_jobposition = $jobposition;
    }

    public function getjobposition () {
        return $this->_jobposition;
    }

    public function setworkingyear ( $workingyear ) {
        $this->_workingyear = $workingyear;
    }

    public function getworkingyear () {
        return $this->_workingyear;
    }

    public function setworkdetails ( $workdetails ) {
        $this->_workdetails = $workdetails;
    }

    public function getworkdetails () {
        return $this->_workdetails;
    }
}
class CV_Skills{
    private $_ID;
    private $_cvID;
    private $_name;
    private $_details;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setcvID ( $cvID ) {
        $this->_cvID = $cvID;
    }

    public function getcvID () {
        return $this->_cvID;
    }

    public function setname ( $name ) {
        $this->_name = $name;
    }

    public function getname () {
        return $this->_name;
    }

    public function setdetails( $details ) {
        $this->_details = $details;
    }

    public function getdetails () {
        return $this->_details;
    }
}

class JOB_Application{
    private $_ID;
    private $_applicantID;
    private $_JobID;
    private $_cvID;
    private $_SubmissionDate;
    private $_jobname;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setapplicantID ( $applicantID ) {
        $this->_applicantID = $applicantID;
    }

    public function getapplicantID () {
        return $this->_applicantID;
    }

    public function setJobID ( $JobID ) {
        $this->_JobID = $JobID;
    }

    public function getJobID () {
        return $this->_JobID;
    }

    public function setcvID( $cvID ) {
        $this->_cvID = $cvID;
    }

    public function getcvID () {
        return $this->_cvID;
    }
    
    public function setSubmissionDate( $SubmissionDate ) {
        $this->_SubmissionDate = $SubmissionDate;
    }

    public function getSubmissionDate () {
        return $this->_SubmissionDate;
    }

    public function setjobname( $jobname ) {
        $this->_jobname = $jobname;
    }

    public function getjobname () {
        return $this->_jobname;
    }
}
?>