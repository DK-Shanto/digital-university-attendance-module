<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.job.inc';


Class JobCVShowDAO{

	private $_DB;
	private $_CV;
	private $_CV_Education;
	private $_CV_Experience;
	private $_CV_Skills;

	public function __construct(){
		$this->_DB = DBUtil::getInstance();
		$this->_CV = new CV();
		$this->_CV_Education = new CV_Education();
		$this->_CV_Experience = new CV_Experience();
		$this->_CV_Skills = new CV_Skills();
	}
	public function getCV($globalUser){

		$this->_DB->doQuery("SELECT * FROM jms_cv where applicantID like '$globalUser'");

		$rows = $this->_DB->getAllRows();

		$row = $rows[0];

	    $this->_CV->setID ( $row['ID']);
	    $this->_CV->setapplicantID ( $row['applicantID'] );   
	    $this->_CV->setName ( $row['Name'] );
	    $this->_CV->setsector ( $row['sector'] );
	    $this->_CV->setemail( $row['email'] );
	    $this->_CV->setphone( $row['phone'] );
	    $this->_CV->setprofile( $row['profile'] );
	    $this->_CV->settechnical_skill ( $row['technical_skill'] );

	    $Education_List = array();
	    $Experience_List = array();
	    $Skills_List = array();
	    $cv_id=$row['ID'];

		$this->_DB->doQuery("SELECT * FROM jms_cv_education where cvID like '$cv_id'");

		$rows2 = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows2); $i++) {
			$row2 = $rows2[$i];
			$this->_CV_Education = new CV_Education();

			$this->_CV_Education->setID ( $row2['ID']);
		    $this->_CV_Education->setcvID ( $row2['cvID']);
		    $this->_CV_Education->setinstituition ( $row2['instituition'] );   
		    $this->_CV_Education->setsubject ( $row2['subject'] );
		    $this->_CV_Education->setcgpa ( $row2['cgpa'] );

		    $Education_List[]=$this->_CV_Education;
			}

		$this->_DB->doQuery("SELECT * FROM jms_cv_experience where cvID like '$cv_id'");

		$rows3 = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows3); $i++) {
			$row3 = $rows3[$i];
			$this->_CV_Experience = new CV_Experience();

			$this->_CV_Education->setID ( $row3['ID']);
		    $this->_CV_Experience->setcvID ( $row3['cvID']);
		    $this->_CV_Experience->setjobname ( $row3['jobname'] );   
		    $this->_CV_Experience->setjobposition ( $row3['jobposition'] );
		    $this->_CV_Experience->setworkingyear ( $row3['workingyear'] );
		    $this->_CV_Experience->setworkdetails ( $row3['workdetails'] );

		    $Experience_List[]=$this->_CV_Experience;
			}

		$this->_DB->doQuery("SELECT * FROM jms_cv_skills where cvID like '$cv_id'");

		$rows4 = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows4); $i++) {
			$row4 = $rows4[$i];
			$this->_CV_Skills = new CV_Skills();

			$this->_CV_Education->setID ( $row4['ID']);
		    $this->_CV_Skills->setcvID ( $row4['cvID']);
		    $this->_CV_Skills->setname ( $row4['name'] );   
		    $this->_CV_Skills->setdetails ( $row4['details'] );

		    $Skills_List[]=$this->_CV_Skills;
			}

		$this->_CV->seteducation( $Education_List);
	    $this->_CV->setexperience( $Experience_List );
	    $this->_CV->setskills ( $Skills_List );


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_CV);

		return $Result;
	}
}
?>