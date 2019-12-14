<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.cca.inc';
//include_once './common/class.common.course.php';


Class CCAORGANIZERDAO{

	private $_DB;
	private $_category;
	private $ccaClass;
	private $_organizer;
	
	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		//$this->_category = new Category();
		$this->ccaClass = new CCAORGANIZER();
	//	$this->_organizer=new Organizer();
	}

	// get all the Schools from the database using the database query



public function AddOrganizer($ADDORG){

		$organizer=$ADDORG->getOrganizer();



		$SQL = "INSERT INTO tbl_organizer(organizerName) VALUES('$organizer') ";

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}


	public function ORGDELETE($CCA){

		//beginning a transaction
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);

		//removing previous Positions

		$SQL_delete = "DELETE from tbl_organizer where org_id ='".$CCA->getidg()."'";
		$SQL_delete = $this->_DB->doQuery($SQL_delete);
//$CC=$CCA->getID();
		//removing previous roles



		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL_delete);

		return $Result;

	}

public function updateorganizer($ADDCAT){




		$SQL = "UPDATE tbl_organizer set organizerName='".$ADDCAT->getOrganizer()."' WHERE org_id='".$ADDCAT->getidg()."'";

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}


	public function readORG($cca){


		$SQL = "SELECT *from tbl_organizer where  org_id='".$cca->getidg()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Role from the database
		$row = $this->_DB->getTopRow();

		$this->_Role = new CCAORGANIZER();

		//preparing the Role object
	    $this->_Role->setOrganizer ( $row['organizerName']);




	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Role);

		return $Result;
	}


	public function getORG()
	{

			$CategoryList = array();

			$this->_DB->doQuery("SELECT * FROM tbl_organizer");

			$rows = $this->_DB->getAllRows();

			for($i = 0; $i < sizeof($rows); $i++)
			 {
				$row = $rows[$i];
				$this->_category = new CCAORGANIZER();
				$this->_category->setidg($row['org_id']);
			    $this->_category->setOrganizer($row['organizerName']);
			    $CategoryList[]=$this->_category;

			}
$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CategoryList);

		return $Result;
 	}


}



?>
