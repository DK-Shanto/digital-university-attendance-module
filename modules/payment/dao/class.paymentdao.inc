<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.payment.inc';
include_once COMMON.'class.common.user.inc';
include_once UTILITY.'class.util.inc';
Class PaymentDAO{

	private $_DB;
	private $_User;
	private $_RegistrationFee;
	private $_Recharge;
	private $_PaymentType;
	private $_HallFee;
	private $_OthersFee;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_User = new User();
		$this->_RegistrationFee = new RegistrationFee();
		$this->_Recharge = new Recharge();
		$this->_PaymentType = new PaymentType();
		$this->_HallFee = new HallFee();
		$this->_OthersFee = new OthersFee();
	}
	public function getUserById($User){
		$ID = $User->getID();

		$SQL = "SELECT UniversityID,FirstName,MiddleName,LastName,DisciplineID,Email FROM ums_user WHERE ID = '$ID'";
		
		$this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_User = new User();

	    $this->_User->setUniversityID ( $row['UniversityID']);
	    $this->_User->setEmail ( $row['Email']);

	    $this->_User->setFirstName( $row['FirstName']." ".$row['MiddleName']." ".$row['LastName'] );
	    
	    $DisciplineID = $row['DisciplineID'];
	    $SQL1 = "SELECT Name FROM ums_discipline WHERE ID = '$DisciplineID'";

		$this->_DB->doQuery($SQL1);
		$row1 = $this->_DB->getTopRow();
	    $this->_User->setDiscipline ( $row1['Name']);
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_User);

		return $Result;
	}
		//paying registration fee with object
	public function setRegistrationPayment($RegistrationFee){
		
		$ID =$RegistrationFee->getID();
		$UniversityID=$RegistrationFee->getUniversityID();
		$Batch =$RegistrationFee->getBatch();
		$Name=$RegistrationFee->getName();
		$Email=$RegistrationFee->getEmail();
		$Term =$RegistrationFee->getTerm();
		$Discipline =$RegistrationFee->getDiscipline();
		$Date =$RegistrationFee->getDate();
		$AdmissionFee =$RegistrationFee->getAdmissionFee();
		$PayBook =$RegistrationFee->getPayBook();
		$Security =$RegistrationFee->getSecurity();
		$Transportation =$RegistrationFee->getTransportation();
		$CourseRegistration =$RegistrationFee->getCourseRegistration();
		$Verification =$RegistrationFee->getVerification();
		$Retake =$RegistrationFee->getRetake();
		$ReRetake =$RegistrationFee->getReRetake();
		$Bncc =$RegistrationFee->getBncc();
		$Library =$RegistrationFee->getLibrary();
		$Medical =$RegistrationFee->getMedical();
		$Cultural =$RegistrationFee->getCultural();
		$ReligiousFee =$RegistrationFee->getReligiousFee();
		$ExaminationFee =$RegistrationFee->getExaminationFee();
		$SessionCharge =$RegistrationFee->getSessionCharge();
		$Gradesheet =$RegistrationFee->getGradesheet();
		$ProvisionalCertificate =$RegistrationFee->getProvisionalCertificate();
		$MainCertificate =$RegistrationFee->getMainCertificate();
		$Transcript =$RegistrationFee->getTranscript();
		$SecurityLibrary =$RegistrationFee->getSecurityLibrary();
		$EquivalenceCertificate =$RegistrationFee->getEquivalenceCertificate();
		$FineLibrary =$RegistrationFee->getFineLibrary();
		$FineRegistration =$RegistrationFee->getFineRegistration();
		$Mc_Mi =$RegistrationFee->getMc_Mi();
		$MphilPhd =$RegistrationFee->getMphilPhd();
		$StudentWelfare =$RegistrationFee->getStudentWelfare();
		$Sports =$RegistrationFee->getSports();
		$Publication =$RegistrationFee->getPublication();
		$Others =$RegistrationFee->getOthers();
		$Total =$RegistrationFee->getTotal();

		$SQL = "INSERT INTO pms_reg_fee VALUES('$ID','$UniversityID', '$Batch' ,'$Name','$Email','$Term','$Discipline','$Date','$AdmissionFee','$PayBook','$Security','$Transportation','$CourseRegistration','$Verification','$Retake','$ReRetake','$Bncc','$Library','$Medical','$Cultural','$ReligiousFee','$ExaminationFee','$SessionCharge','$Gradesheet','$ProvisionalCertificate','$MainCertificate','$Transcript','$SecurityLibrary','$EquivalenceCertificate','$FineLibrary','$FineRegistration','$Mc_Mi','$MphilPhd','$StudentWelfare','$Sports','$Publication','$Others','$Total')";


		$SQL = $this->_DB->doQuery($SQL);
		//updating balance after paying fee

		$SQL2 = "SELECT Amount FROM pms_recharge WHERE Email='$Email'";
		$SQL2 = $this->_DB->doQuery($SQL2);
		$row = $this->_DB->getTopRow();

			$amount = $row['Amount'] - $Total;
			$SQL3 = "UPDATE pms_recharge SET Amount ='$amount' WHERE Email='$Email'";
			$SQL3 = $this->_DB->doQuery($SQL3);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;		
	}

	//Recharge Amount
	public function setRechargeAmount($Recharge){
		
		$ID =$Recharge->getID();
		$Date =$Recharge->getDate();
		$Email=$Recharge->getEmail();
		$Amount=$Recharge->getAmount();

		//getting account information using email id
		$SQL2 = "SELECT Amount FROM pms_recharge WHERE Email='$Email'";
		$SQL2 = $this->_DB->doQuery($SQL2);
		$row = $this->_DB->getTopRow();
		if(is_null($row['Amount']))
		{
		$SQL = "INSERT INTO pms_recharge VALUES('$ID','$Date','$Email','$Amount')";


		$SQL = $this->_DB->doQuery($SQL);
		}

		else
		{
			$amount = $Amount + $row['Amount'];
			$SQL3 = "UPDATE pms_recharge SET Amount ='$amount', `Date` = '$Date' WHERE Email='$Email'";
			$SQL3 = $this->_DB->doQuery($SQL3);
		}

		//inserting data for recharge log
		$SQL1 = "INSERT INTO  pms_recharge_log (`Date`, Email, Amount) VALUES('$Date','$Email','$Amount')";


		$SQL1 = $this->_DB->doQuery($SQL1);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL1);

		return $Result;		
	}
	//get recharge log
	public function getRechargeLog(){

		$LogList = array();

		$this->_DB->doQuery("SELECT * FROM pms_recharge_log ORDER BY ID DESC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Recharge = new Recharge();

		    $this->_Recharge->setID ( $row['ID']);
			$this->_Recharge->setDate ( $row['Date']);
		    $this->_Recharge->setEmail ( $row['Email']);
			$this->_Recharge->setAmount ( $row['Amount']);
		    $LogList[]=$this->_Recharge;
   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($LogList);

		return $Result;
	}

	//get account details by email
		public function getAccountDetails($Account){
		$Email = $Account->getEmail();
		$SQL = "SELECT * FROM pms_recharge WHERE Email='$Email'";
		
		$this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();
		$this->_Recharge = new Recharge();

	    $this->_Recharge->setDate ( $row['Date']);
	    $this->_Recharge->setEmail ( $row['Email']);
	    $this->_Recharge->setAmount ( $row['Amount']);

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Recharge);

		return $Result;
	}
	//getting registration fee details
	public function getRegistrationFee($RegistrationFee){
		$ID = $RegistrationFee->getID();
		$SQL = "SELECT * FROM pms_reg_fee WHERE ID='$ID'";
		$this->_DB->doQuery($SQL);
		$row = $this->_DB->getTopRow();
		$this->_RegistrationFee = new RegistrationFee();
		$this->_RegistrationFee->setID ( $row['ID']);	    	
		$this->_RegistrationFee->setUniversityID ( $row['UniversityID']);
		$this->_RegistrationFee->setBatch ( $row['Batch']);
		$this->_RegistrationFee->setName ( $row['Name']);
		$this->_RegistrationFee->setEmail ( $row['Email']);
		$this->_RegistrationFee->setTerm ( $row['Term']);
		$this->_RegistrationFee->setDiscipline ( $row['Discipline']);
		$this->_RegistrationFee->setDate ( $row['Date']);
		$this->_RegistrationFee->setAdmissionFee ( $row['AdmissionFee']);
		$this->_RegistrationFee->setPayBook ( $row['PayBook']);
		$this->_RegistrationFee->setSecurity ( $row['Security']);
		$this->_RegistrationFee->setTransportation ( $row['Transportation']);
		$this->_RegistrationFee->setCourseRegistration ( $row['CourseRegistration']);
		$this->_RegistrationFee->setVerification ( $row['Verification']);
		$this->_RegistrationFee->setRetake ( $row['Retake']);
		$this->_RegistrationFee->setReRetake ( $row['ReRetake']);
		$this->_RegistrationFee->setBncc ( $row['Bncc']);
		$this->_RegistrationFee->setLibrary ( $row['Library']);
		$this->_RegistrationFee->setMedical ( $row['Medical']);
		$this->_RegistrationFee->setCultural ( $row['Cultural']);
		$this->_RegistrationFee->setReligiousFee ( $row['ReligiousFee']);
		$this->_RegistrationFee->setExaminationFee ( $row['ExaminationFee']);
		$this->_RegistrationFee->setSessionCharge ( $row['SessionCharge']);
		$this->_RegistrationFee->setGradesheet ( $row['Gradesheet']);
		$this->_RegistrationFee->setProvisionalCertificate ( $row['ProvisionalCertificate']);
		$this->_RegistrationFee->setMainCertificate ( $row['MainCertificate']);
		$this->_RegistrationFee->setTranscript ( $row['Transcript']);
		$this->_RegistrationFee->setSecurityLibrary ( $row['SecurityLibrary']);
		$this->_RegistrationFee->setEquivalenceCertificate ( $row['EquivalenceCertificate']);
		$this->_RegistrationFee->setFineLibrary ( $row['FineLibrary']);
		$this->_RegistrationFee->setFineRegistration ( $row['FineRegistration']);
		$this->_RegistrationFee->setMc_Mi ( $row['Mc_Mi']);
		$this->_RegistrationFee->setMphilPhd ( $row['MphilPhd']);
		$this->_RegistrationFee->setStudentWelfare ( $row['StudentWelfare']);
		$this->_RegistrationFee->setSports ( $row['Sports']);
		$this->_RegistrationFee->setPublication ( $row['Publication']);
		$this->_RegistrationFee->setOthers ( $row['Others']);
		$this->_RegistrationFee->setTotal ( $row['Total']);
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_RegistrationFee);

		return $Result;		
	}
		

		//setting payment type
		public function setPaymentType($PaymentType){
		$ID =$PaymentType->getID();
		$PID =$PaymentType->getPID();		
		$UniversityID=$PaymentType->getUniversityID();
		$Type=$PaymentType->getType();
		$Date=$PaymentType->getDate();
		$SQL = "INSERT pms_payment_type VALUES('$ID', '$PID' ,'$UniversityID','$Type','$Date')";
		$SQL = $this->_DB->doQuery($SQL);
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($RegistrationFee);
		return $Result;
	}
	//getting payment type
	public function getPaymentType($User){

		$UID = $User->getUniversityID();
		$PaymentType = array();

		$SQL = "SELECT * FROM pms_payment_type WHERE UniversityID ='$UID' ORDER BY `Date` DESC";
		$this->_DB->doQuery($SQL);
		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_PaymentType = new PaymentType();

		    $this->_PaymentType->setID ( $row['ID']);
		    $this->_PaymentType->setPID ( $row['PID']);
		    $this->_PaymentType->setUniversityID ( $row['UniversityID']);
		    $this->_PaymentType->setType( $row['Type']);
			$this->_PaymentType->setDate( $row['Date']);

		    $PaymentType[]=$this->_PaymentType;
   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($PaymentType);

		return $Result;
	}
//getting registration fee by student id
	public function getRegistrationFeeBySid($RegistrationFee){
		$LogList = array();
		$SID = $RegistrationFee->getUniversityID();
		$SQL = "SELECT * FROM pms_reg_fee WHERE UniversityID='$SID' ORDER BY `Date` DESC";
		$this->_DB->doQuery($SQL);
		$rows = $this->_DB->getAllRows();
		for($i = 0; $i < sizeof($rows); $i++) {
		$row = $rows[$i];
		$this->_RegistrationFee = new RegistrationFee();
		$this->_RegistrationFee->setID ( $row['ID']);	    	
		$this->_RegistrationFee->setUniversityID ( $row['UniversityID']);
		$this->_RegistrationFee->setBatch ( $row['Batch']);
		$this->_RegistrationFee->setName ( $row['Name']);
		$this->_RegistrationFee->setEmail ( $row['Email']);
		$this->_RegistrationFee->setTerm ( $row['Term']);
		$this->_RegistrationFee->setDiscipline ( $row['Discipline']);
		$this->_RegistrationFee->setDate ( $row['Date']);
		$this->_RegistrationFee->setAdmissionFee ( $row['AdmissionFee']);
		$this->_RegistrationFee->setPayBook ( $row['PayBook']);
		$this->_RegistrationFee->setSecurity ( $row['Security']);
		$this->_RegistrationFee->setTransportation ( $row['Transportation']);
		$this->_RegistrationFee->setCourseRegistration ( $row['CourseRegistration']);
		$this->_RegistrationFee->setVerification ( $row['Verification']);
		$this->_RegistrationFee->setRetake ( $row['Retake']);
		$this->_RegistrationFee->setReRetake ( $row['ReRetake']);
		$this->_RegistrationFee->setBncc ( $row['Bncc']);
		$this->_RegistrationFee->setLibrary ( $row['Library']);
		$this->_RegistrationFee->setMedical ( $row['Medical']);
		$this->_RegistrationFee->setCultural ( $row['Cultural']);
		$this->_RegistrationFee->setReligiousFee ( $row['ReligiousFee']);
		$this->_RegistrationFee->setExaminationFee ( $row['ExaminationFee']);
		$this->_RegistrationFee->setSessionCharge ( $row['SessionCharge']);
		$this->_RegistrationFee->setGradesheet ( $row['Gradesheet']);
		$this->_RegistrationFee->setProvisionalCertificate ( $row['ProvisionalCertificate']);
		$this->_RegistrationFee->setMainCertificate ( $row['MainCertificate']);
		$this->_RegistrationFee->setTranscript ( $row['Transcript']);
		$this->_RegistrationFee->setSecurityLibrary ( $row['SecurityLibrary']);
		$this->_RegistrationFee->setEquivalenceCertificate ( $row['EquivalenceCertificate']);
		$this->_RegistrationFee->setFineLibrary ( $row['FineLibrary']);
		$this->_RegistrationFee->setFineRegistration ( $row['FineRegistration']);
		$this->_RegistrationFee->setMc_Mi ( $row['Mc_Mi']);
		$this->_RegistrationFee->setMphilPhd ( $row['MphilPhd']);
		$this->_RegistrationFee->setStudentWelfare ( $row['StudentWelfare']);
		$this->_RegistrationFee->setSports ( $row['Sports']);
		$this->_RegistrationFee->setPublication ( $row['Publication']);
		$this->_RegistrationFee->setOthers ( $row['Others']);
		$this->_RegistrationFee->setTotal ( $row['Total']);
		
		$LogList[]=$this->_RegistrationFee;  
		}
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($LogList);

		return $Result;		
	}

		//paying Hall fee with object
	public function setHallPayment($HallFee){
		
		$ID =$HallFee->getID();
		$UniversityID=$HallFee->getUniversityID();
		$Batch =$HallFee->getBatch();
		$Name=$HallFee->getName();
		$Email=$HallFee->getEmail();
		$HallName=$HallFee->getHallName();
		$FiscalYear=$HallFee->getFiscalYear();
    	$Discipline=$HallFee->getDiscipline();
    	$Date=$HallFee->getDate();
    	$Admission=$HallFee->getAdmission();
    	$Institutional=$HallFee->getInstitutional();
    	$IdentificationCard=$HallFee->getIdentificationCard();
    	$SeatRent=$HallFee->getSeatRent();
    	$Utensil=$HallFee->getUtensil();
    	$CommonRoom=$HallFee->getCommonRoom();
    	$Sports=$HallFee->getSports();
    	$ReligiousEvent=$HallFee->getReligiousEvent();
    	$SecurityReturnable=$HallFee->getSecurityReturnable();
    	$Contingency=$HallFee->getContingency();
    	$HallAnniversary=$HallFee->getHallAnniversary();
    	$Fine=$HallFee->getFine();
    	$Others=$HallFee->getOthers();
    	$Total=$HallFee->getTotal();

		$SQL = "INSERT INTO pms_hall_fee VALUES('$ID','$UniversityID', '$Batch' ,'$Name','$Email','$HallName','$FiscalYear','$Discipline','$Date','$Admission','$Institutional','$IdentificationCard','$SeatRent','$Utensil','$CommonRoom','$Sports','$ReligiousEvent','$SecurityReturnable','$Contingency','$HallAnniversary','$Fine','$Others','$Total')";


		$SQL = $this->_DB->doQuery($SQL);
		//updating balance after paying fee

		$SQL2 = "SELECT Amount FROM pms_recharge WHERE Email='$Email'";
		$SQL2 = $this->_DB->doQuery($SQL2);
		$row = $this->_DB->getTopRow();

			$amount = $row['Amount'] - $Total;
			$SQL3 = "UPDATE pms_recharge SET Amount ='$amount' WHERE Email='$Email'";
			$SQL3 = $this->_DB->doQuery($SQL3);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;		
	}
	//get hall fee detials using hall payment id
	public function getHallFee($HallFee){
		$ID = $HallFee->getID();
		$SQL = "SELECT * FROM pms_hall_fee WHERE ID='$ID'";
		$this->_DB->doQuery($SQL);
		$row = $this->_DB->getTopRow();

		$this->_HallFee->setID ( $row['ID']);
		$this->_HallFee->setUniversityID ( $row['UniversityID']);
		$this->_HallFee->setBatch ( $row['Batch']);
		$this->_HallFee->setName ( $row['Name']);
		$this->_HallFee->setEmail ( $row['Email']);
		$this->_HallFee->setHallName ( $row['HallName']);
		$this->_HallFee->setFiscalYear ( $row['FiscalYear']);
		$this->_HallFee->setDiscipline ( $row['Discipline']);
		$this->_HallFee->setDate ( $row['Date']);
		$this->_HallFee->setAdmission ( $row['Admission']);
		$this->_HallFee->setInstitutional($row['Institutional']);
		$this->_HallFee->setIdentificationCard ( $row['IdentificationCard']);
		$this->_HallFee->setSeatRent ( $row['SeatRent']);
		$this->_HallFee->setUtensil ( $row['Utensil']);
		$this->_HallFee->setCommonRoom ( $row['CommonRoom']);
		$this->_HallFee->setSports ( $row['Sports']);
		$this->_HallFee->setReligiousEvent ( $row['ReligiousEvent']);
		$this->_HallFee->setSecurityReturnable ( $row['SecurityReturnable']);
		$this->_HallFee->setContingency ( $row['Contingency']);
		$this->_HallFee->setHallAnniversary ( $row['HallAnniversary']);
		$this->_HallFee->setFine ( $row['Fine']);
		$this->_HallFee->setOthers ( $row['Others']);
		$this->_HallFee->setTotal ( $row['Total']);
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_HallFee);

		return $Result;		
	}

	//getting Hall fee by student id
	public function getHallFeeBySid($HallFee){
		$LogList = array();
		$SID = $HallFee->getUniversityID();
		$SQL = "SELECT * FROM pms_hall_fee WHERE UniversityID='$SID' ORDER BY `Date` DESC";
		$this->_DB->doQuery($SQL);
		$rows = $this->_DB->getAllRows();
		for($i = 0; $i < sizeof($rows); $i++) {
		$row = $rows[$i];
		$this->_HallFee = new HallFee();
		$this->_HallFee->setID ( $row['ID']);
		$this->_HallFee->setUniversityID ( $row['UniversityID']);
		$this->_HallFee->setBatch ( $row['Batch']);
		$this->_HallFee->setName ( $row['Name']);
		$this->_HallFee->setEmail ( $row['Email']);
		$this->_HallFee->setHallName ( $row['HallName']);
		$this->_HallFee->setFiscalYear ( $row['FiscalYear']);
		$this->_HallFee->setDiscipline ( $row['Discipline']);
		$this->_HallFee->setDate ( $row['Date']);
		$this->_HallFee->setAdmission ( $row['Admission']);
		$this->_HallFee->setInstitutional($row['Institutional']);
		$this->_HallFee->setIdentificationCard ( $row['IdentificationCard']);
		$this->_HallFee->setSeatRent ( $row['SeatRent']);
		$this->_HallFee->setUtensil ( $row['Utensil']);
		$this->_HallFee->setCommonRoom ( $row['CommonRoom']);
		$this->_HallFee->setSports ( $row['Sports']);
		$this->_HallFee->setReligiousEvent ( $row['ReligiousEvent']);
		$this->_HallFee->setSecurityReturnable ( $row['SecurityReturnable']);
		$this->_HallFee->setContingency ( $row['Contingency']);
		$this->_HallFee->setHallAnniversary ( $row['HallAnniversary']);
		$this->_HallFee->setFine ( $row['Fine']);
		$this->_HallFee->setOthers ( $row['Others']);
		$this->_HallFee->setTotal ( $row['Total']);
		$LogList[]=$this->_HallFee;  
		}
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($LogList);

		return $Result;		
	}

//paying Others fee with object
	public function setOthersPayment($Others){
		
		$ID =$Others->getID();
		$UniversityID=$Others->getUniversityID();
		$Batch =$Others->getBatch();
		$Name=$Others->getName();
		$Email=$Others->getEmail();
    	$Discipline=$Others->getDiscipline();
    	$Date=$Others->getDate();
    	$Description=$Others->getDescription();
    	$Total=$Others->getTotal();

		$SQL = "INSERT INTO pms_others_fee VALUES('$ID','$UniversityID', '$Batch' ,'$Name','$Email','$Discipline','$Date', '$Description', '$Total')";


		$SQL = $this->_DB->doQuery($SQL);
		//updating balance after paying fee

		$SQL2 = "SELECT Amount FROM pms_recharge WHERE Email='$Email'";
		$SQL2 = $this->_DB->doQuery($SQL2);
		$row = $this->_DB->getTopRow();

			$amount = $row['Amount'] - $Total;
			$SQL3 = "UPDATE pms_recharge SET Amount ='$amount' WHERE Email='$Email'";
			$SQL3 = $this->_DB->doQuery($SQL3);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;		
	}
	//get others fee detials using others payment id
	public function getOthersFee($OthersFee){
		$ID = $OthersFee->getID();
		$SQL = "SELECT * FROM pms_others_fee WHERE ID='$ID'";
		$this->_DB->doQuery($SQL);
		$row = $this->_DB->getTopRow();
		$this->_OthersFee = new OthersFee();
		$this->_OthersFee->setID ( $row['ID']);
		$this->_OthersFee->setUniversityID ( $row['UniversityID']);
		$this->_OthersFee->setBatch ( $row['Batch']);
		$this->_OthersFee->setName ( $row['Name']);
		$this->_OthersFee->setEmail ( $row['Email']);
		$this->_OthersFee->setDiscipline ( $row['Discipline']);
		$this->_OthersFee->setDate ( $row['Date']);
		$this->_OthersFee->setDescription ( $row['Description']);
		$this->_OthersFee->setTotal ( $row['Total']);
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_OthersFee);

		return $Result;		
	}

	//getting Others fee by student id
	public function getOthersFeeBySid($HallFee){
		$LogList = array();
		$SID = $HallFee->getUniversityID();
		$SQL = "SELECT * FROM pms_others_fee WHERE UniversityID='$SID' ORDER BY `Date` DESC";
		$this->_DB->doQuery($SQL);
		$rows = $this->_DB->getAllRows();
		for($i = 0; $i < sizeof($rows); $i++) {
		$row = $rows[$i];
		$this->_OthersFee = new OthersFee();
		$this->_OthersFee->setID ( $row['ID']);
		$this->_OthersFee->setUniversityID ( $row['UniversityID']);
		$this->_OthersFee->setBatch ( $row['Batch']);
		$this->_OthersFee->setName ( $row['Name']);
		$this->_OthersFee->setEmail ( $row['Email']);
		$this->_OthersFee->setDiscipline ( $row['Discipline']);
		$this->_OthersFee->setDate ( $row['Date']);
		$this->_OthersFee->setDescription ( $row['Description']);
		$this->_OthersFee->setTotal ( $row['Total']);
		$LogList[]=$this->_OthersFee;  
		}
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($LogList);

		return $Result;		
	}
}
?>