<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_PAYMENT.'bao/class.paymentbao.inc';
$_PaymentBAO = new PaymentBAO();
$_DB = DBUtil::getInstance();
$globalUser = '';
$globalUser = $_SESSION["globalUser"];
$User = new User();
$User->setID($globalUser->getID());
$getROW = $_PaymentBAO->getUserById($User)->getResultObject();
//getting email
$email = $getROW->getEmail();
$getAccount = $_PaymentBAO->getAccountDetails($getROW)->getResultObject();
$balance = $getAccount->getAmount();
//getting discipline
$Discipline = $getROW->getDiscipline();
//setting batch from university id
$UID = $getROW->getUniversityID();
//setting batch 
$Batch =  intval($UID /10000);
//setting name
$name = $getROW->getFirstName();
//getting current date
date_default_timezone_set("Asia/Dhaka");
$date = date('Y/m/d');
/* saving the registration Payment Receipt*/
if(isset($_POST['payr']))
{
	 $Total = ($_POST['af'] + $_POST['pb'] + $_POST['scg'] + $_POST['tp'] + $_POST['cr'] + $_POST['vf'] + $_POST['rt'] + $_POST['rrt'] + $_POST['bncc'] + $_POST['lb'] + $_POST['med'] + $_POST['cl'] + $_POST['rg'] + $_POST['ef'] + $_POST['sc'] + $_POST['gs'] + $_POST['pc'] + $_POST['mc'] + $_POST['tsc'] + $_POST['scl'] + $_POST['ec'] + $_POST['flib'] + $_POST['fcr'] + $_POST['mmc'] + $_POST['mfph'] + $_POST['sw'] + $_POST['sp'] + $_POST['pl'] + $_POST['ot'] );
	 

	 if($Total > $balance)
	 {
	 	header("Location: message.php");	 	
	 }
	 else
	 {

	 $RegistrationFee = new RegistrationFee();
	 $RID = Util::getGUID();
	 $RegistrationFee->setID($RID);
     $RegistrationFee->setUniversityID($UID);
     $RegistrationFee->setBatch($Batch);
     $RegistrationFee->setName($name);
     $RegistrationFee->setEmail($email);
     $RegistrationFee->setDate($date);
     $RegistrationFee->setDiscipline($Discipline);
     $RegistrationFee->setTerm($_DB->secureInput($_POST['trm']));
     $RegistrationFee->setAdmissionFee($_DB->secureInput($_POST['af']));
     $RegistrationFee->setPayBook($_DB->secureInput($_POST['pb']));
	 $RegistrationFee->setSecurity($_DB->secureInput($_POST['scg']));
	 $RegistrationFee->setTransportation($_DB->secureInput($_POST['tp']));
	 $RegistrationFee->setCourseRegistration($_DB->secureInput($_POST['cr']));
	 $RegistrationFee->setVerification($_DB->secureInput($_POST['vf']));
	 $RegistrationFee->setRetake($_DB->secureInput($_POST['rt']));
	 $RegistrationFee->setReRetake($_DB->secureInput($_POST['rrt']));
	 $RegistrationFee->setBncc($_DB->secureInput($_POST['bncc']));
	 $RegistrationFee->setLibrary($_DB->secureInput($_POST['lb']));
	 $RegistrationFee->setMedical($_DB->secureInput($_POST['med']));
	 $RegistrationFee->setCultural($_DB->secureInput($_POST['cl']));
	 $RegistrationFee->setReligiousFee($_DB->secureInput($_POST['rg']));
	 $RegistrationFee->setExaminationFee($_DB->secureInput($_POST['ef']));
	 $RegistrationFee->setSessionCharge($_DB->secureInput($_POST['sc']));
	 $RegistrationFee->setGradesheet($_DB->secureInput($_POST['gs']));
	 $RegistrationFee->setProvisionalCertificate($_DB->secureInput($_POST['pc']));
	 $RegistrationFee->setMainCertificate($_DB->secureInput($_POST['mc']));
	 $RegistrationFee->setTranscript($_DB->secureInput($_POST['tsc']));
	 $RegistrationFee->setSecurityLibrary($_DB->secureInput($_POST['scl']));
	 $RegistrationFee->setEquivalenceCertificate($_DB->secureInput($_POST['ec']));
	 $RegistrationFee->setFineLibrary($_DB->secureInput($_POST['flib']));
	 $RegistrationFee->setFineRegistration($_DB->secureInput($_POST['fcr']));
	 $RegistrationFee->setMc_Mi($_DB->secureInput($_POST['mmc']));
	 $RegistrationFee->setMphilPhd($_DB->secureInput($_POST['mfph']));
	 $RegistrationFee->setStudentWelfare($_DB->secureInput($_POST['sw']));
	 $RegistrationFee->setSports($_DB->secureInput($_POST['sp']));
	 $RegistrationFee->setPublication($_DB->secureInput($_POST['pl']));
	 $RegistrationFee->setOthers($_DB->secureInput($_POST['ot']));
	 $RegistrationFee->setTotal($Total);
	 $_PaymentBAO->setRegistrationPayment($RegistrationFee);
	 //for setting payment type
	 $Type = "Registration Fee";
	 		date_default_timezone_set("Asia/Dhaka");
		$Date = date('Y/m/d h:i:s', time());
	 $PaymentType = new PaymentType();
	 $PaymentType->setID(Util::getGUID());
	 $PaymentType->setPID($RID);
	 $PaymentType->setUniversityID($UID);
	 $PaymentType->setType($Type);
	 $PaymentType->setDate($Date);
	 $_PaymentBAO->setPaymentType($PaymentType);
	 header("Location: myaccount.php");	
	 }
}
/* saving the hall Payment Receipt*/
if(isset($_POST['payh']))
{
	 $Total = ($_POST['adm'] + $_POST['ins'] + $_POST['ic'] + $_POST['sr'] + $_POST['ut'] + $_POST['cr'] + $_POST['sp'] + $_POST['re'] + $_POST['scr'] + $_POST['cgn'] + $_POST['ha'] + $_POST['fn'] + $_POST['ot'] );

	 if($Total > $balance)
	 {
	 	header("Location: message.php");
	 }
	 else
	 {

	 $HallFee = new HallFee();
	 $HID = Util::getGUID();
	 $HallFee->setID($HID);
     $HallFee->setUniversityID($UID);
     $HallFee->setBatch($Batch);
     $HallFee->setName($name);
     $HallFee->setEmail($email);
     $HallFee->setDate($date);
     $HallFee->setDiscipline($Discipline);
     $HallFee->setHallName($_DB->secureInput($_POST['hname']));
     $HallFee->setFiscalYear($_DB->secureInput($_POST['fisy']));
     $HallFee->setAdmission($_DB->secureInput($_POST['adm']));
     $HallFee->setInstitutional($_DB->secureInput($_POST['ins']));
	 $HallFee->setIdentificationCard($_DB->secureInput($_POST['ic']));
	 $HallFee->setSeatRent($_DB->secureInput($_POST['sr']));
	 $HallFee->setUtensil($_DB->secureInput($_POST['ut']));
	 $HallFee->setCommonRoom($_DB->secureInput($_POST['cr']));
	 $HallFee->setSports($_DB->secureInput($_POST['sp']));
	 $HallFee->setReligiousEvent($_DB->secureInput($_POST['re']));
	 $HallFee->setSecurityReturnable($_DB->secureInput($_POST['scr']));
	 $HallFee->setContingency($_DB->secureInput($_POST['cgn']));
	 $HallFee->setHallAnniversary($_DB->secureInput($_POST['ha']));
	 $HallFee->setFine($_DB->secureInput($_POST['fn']));
	 $HallFee->setOthers($_DB->secureInput($_POST['ot']));

	 $HallFee->setTotal($Total);
	 $_PaymentBAO->setHallPayment($HallFee);
	 //for setting payment type
	 $Type = "Hall Fee";
	 		date_default_timezone_set("Asia/Dhaka");
		$Date = date('Y/m/d h:i:s', time());
	 $PaymentType = new PaymentType();
	 $PaymentType->setID(Util::getGUID());
	 $PaymentType->setPID($HID);
	 $PaymentType->setUniversityID($UID);
	 $PaymentType->setType($Type);
	 $PaymentType->setDate($Date);
	 $_PaymentBAO->setPaymentType($PaymentType);
	 header("Location: myaccount.php");
	 }
}
//saving others payment details
if(isset($_POST['payo']))
{
	 $Total = $_POST['amount'];

	 if($Total > $balance)
	 {
	 	header("Location: message.php");
	 }
	 else
	 {

	 $Others = new OthersFee();
	 $OID = Util::getGUID();
	 $Others->setID($OID);
     $Others->setUniversityID($UID);
     $Others->setBatch($Batch);
     $Others->setName($name);
     $Others->setEmail($email);
     $Others->setDate($date);
     $Others->setDiscipline($Discipline);
     $Others->setDescription($_DB->secureInput($_POST['desc']));
	 $Others->setTotal($Total);
	 $_PaymentBAO->setOthersPayment($Others);
	 //for setting payment type
	 $Type = "Others Fee";
	 	 		date_default_timezone_set("Asia/Dhaka");
		$Date = date('Y/m/d h:i:s', time());
	 $PaymentType = new PaymentType();
	 $PaymentType->setID(Util::getGUID());
	 $PaymentType->setPID($OID);
	 $PaymentType->setUniversityID($UID);
	 $PaymentType->setType($Type);
	 $PaymentType->setDate($Date);
	 $_PaymentBAO->setPaymentType($PaymentType);
	 header("Location: myaccount.php");
	 }
}
?>

