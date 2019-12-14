<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.scholarship.inc';

Class ScholarshipDAO{
	private $_DB;
	private $_Scholarship;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Scholarship = new Scholarship();
	}

	// get all the scholarships from the database using the database query
	public function getAllScholarships(){

		$ScholarshipList = array();

		// $this->_DB->doQuery("SELECT * FROM ums_user where IsDeleted is null 
		// 	order by (UniversityID * 1) ASC");
		$this->_DB->doQuery("SELECT * FROM sms_scholarship
			order by (id * 1) ASC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
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

		    $ScholarshipList[]=$this->_Scholarship;
   
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($ScholarshipList);

		return $Result;
	}

	//create new job request with the job object
	public function newScholarshipRequest($Scholarship){

		$Title=$Scholarship->getTitle();
		$Subtitle=$Scholarship->getSubtitle();
		$Category=$Scholarship->getCategory();
		$PublishDate=date("Y-m-d");
		$Organization=$Scholarship->getOrganization();
		$Gender=$Scholarship->getGender();
		$AgeLimit = $Scholarship->getAgeLimit();
		
		$Email=$Scholarship->getEmail();
		$ContactNumber = $Scholarship->getContactNumber();	
		$Amount=$Scholarship->getScholarshipAmount();
		$LastDateOfApplication = $Scholarship->getLastDateOfApplication();	


		$SQL = "INSERT INTO sms_scholarship(title,subTitle,category,publishDate,organization,gender,ageLimit,email,contact,amount,lastDate)

		 	VALUES('$Title','$Subtitle','$Category','$PublishDate','$Organization','$Gender','$AgeLimit','$Email','$ContactNumber','$Amount','$LastDateOfApplication')";

		//echo $SQL; 	

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the Job
		$SQL = $this->_DB->doQuery($SQL);	
	
		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("New Scholarship Request Submitted Successfully.");

		return $Result;
	}


	//delete an user based on its id of the database
	public function deleteScholarship($Scholarship){

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
	
		//removing previous Positions 

		$SQL_delete = "DELETE from sms_scholarship where id ='".$Scholarship->getID()."'";
		$SQL_delete = $this->_DB->doQuery($SQL_delete);


		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Scholarship Deleted Successfully.");

		return $Result;

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


	//update an scholarship object based on its id information
	public function updateScholarship($Scholarship){

		$ID = $Scholarship->getID();
		$Title=$Scholarship->getTitle();
		$Subtitle=$Scholarship->getSubtitle();
		$Category=$Scholarship->getCategory();
		$PublishDate=date("Y-m-d");
		$Organization=$Scholarship->getOrganization();
		$Gender=$Scholarship->getGender();
		$AgeLimit = $Scholarship->getAgeLimit();
		$Email=$Scholarship->getEmail();
		$ContactNumber = $Scholarship->getContactNumber();	
		$Amount=$Scholarship->getScholarshipAmount();
		$LastDateOfApplication = $Scholarship->getLastDateOfApplication();	


		$SQL = "UPDATE sms_scholarship SET 
			title='$Title', subTitle='$Subtitle', category='$Category', publishDate='$PublishDate', organization='$Organization', gender='$Gender', ageLimit='$AgeLimit', email='$Email', contact='$ContactNumber', amount='$Amount', lastDate='$LastDateOfApplication' WHERE id='$ID'";

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//updating the user
		$SQL = $this->_DB->doQuery($SQL);
				
		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Scholarship updated Successfully");

		return $Result;

	}

}
?>