<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.job.inc';
include_once COMMON.'class.common.user.inc';


Class JobApplicationDAO{

	private $_DB;
	private $_JOB_Application;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_JOB_Application = new JOB_Application();
	}

	public function getMyApplication($globaluser){

		$ApplicationList = array();

		$this->_DB->doQuery("SELECT * FROM jms_applicant where applicantID like '$globaluser'");

		$rows = $this->_DB->getAllRows();


		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_JOB_Application = new JOB_Application();

		    $this->_JOB_Application->setID ( $row['ID']);
		    $this->_JOB_Application->setapplicantID ( $row['applicantID'] );   
		    $this->_JOB_Application->setJobID ( $row['JobID'] );
		    $this->_JOB_Application->setcvID ( $row['cvID'] );
		    $this->_JOB_Application->setSubmissionDate( $row['SubmissionDate'] );

		    $this->_DB->doQuery("SELECT * FROM jms_job where ID like '".$row['JobID']."'");

		    $row = $this->_DB->getTopRow();

		    $this->_JOB_Application->setjobname( $row['Title'] );


		    $ApplicationList[]=$this->_JOB_Application;
   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($ApplicationList);

		return $Result;
	}

	public function getAllApplication(){

		$ApplicationList = array();

		$this->_DB->doQuery("SELECT * FROM jms_applicant");

		$rows = $this->_DB->getAllRows();


		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_JOB_Application = new JOB_Application();

		    $this->_JOB_Application->setID ( $row['ID']);
		    $this->_JOB_Application->setapplicantID ( $row['applicantID'] );   
		    $this->_JOB_Application->setJobID ( $row['JobID'] );
		    $this->_JOB_Application->setcvID ( $row['cvID'] );
		    $this->_JOB_Application->setSubmissionDate( $row['SubmissionDate'] );

		    $this->_DB->doQuery("SELECT * FROM jms_job where ID like '".$row['JobID']."'");

			$row = $this->_DB->getTopRow();

		    $this->_JOB_Application->setjobname( $row['Title'] );


		    $ApplicationList[]=$this->_JOB_Application;
   
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($ApplicationList);

		return $Result;
	}
}

?>