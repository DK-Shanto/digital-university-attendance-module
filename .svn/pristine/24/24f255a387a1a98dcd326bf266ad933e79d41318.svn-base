

<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.scholarship.inc';
include_once COMMON.'class.common.user.inc';



Class ScholarshipDAO{
	private $_DB;
	private $_Scholarship;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Scholarship = new Scholarship();
	}
	public function readScholarship($Scholarship){

		$SQL = "SELECT * from sms_scholarship where id ='".$Scholarship->getID()."'";

		$this->_DB->doQuery($SQL);

		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		$this->_Scholarship = new Scholarship();

		$this->_Scholarship->setID ( $row['id']);
	    $this->_Scholarship->setTitle ( $row['title']);
	    $this->_Scholarship->setSubtitle ( $row['subTitle'] );   
	    $this->_Scholarship->setCategory ( $row['category'] );
	    $this->_Scholarship->setOrganization ( $row['organization'] );
	    $this->_Scholarship->setPublishDate ( $row['publishDate'] );
	    $this->_Scholarship->setGender( $row['gender'] );
	    $this->_Scholarship->setAgeLimit( $row['ageLimit'] );
	    $this->_Scholarship->setEmail( $row['email'] );
	    $this->_Scholarship->setContactNumber( $row['contact'] );
	    $this->_Scholarship->setScholarshipAmount( $row['amount'] );
	    $this->_Scholarship->setLastDateOfApplication( $row['lastDate'] );


	    $Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Scholarship);

		return $Result;
	}
}

Class StudentHasScholarshipDAO{
	private $_DB;
	private $_StudentHasScholarship;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_StudentHasScholarship = new StudentHasScholarship();
	}

	

	//create new job request with the job object
	public function getStudentHasScholarshipByUniversityID($User){

	    $StudentHasScholarshipList = array();

	    $StudentID = $User->getUniversityID();

	    $this->_DB->doQuery("SELECT * from sms_scholarship_applyscholarship where studentId='$StudentID' and status='approved'");

		$rows = $this->_DB->getAllRows();

		if(sizeof($rows)>0){

			for($i = 0; $i < sizeof($rows); $i++) {
				$row = $rows[$i];
				$this->_StudentHasScholarship = new StudentHasScholarship();

				$this->_StudentHasScholarship->setUniversityID ( $row['studentId']);
			    $this->_StudentHasScholarship->setScholarshipID ( $row['scholarshipId']);

			    $StudentHasScholarshipList[]=$this->_StudentHasScholarship;
	   
			}


			$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject($StudentHasScholarshipList);

			return $Result;
		}
		else{
			$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject("null");

			return $Result;
		}
	}
}

?>	