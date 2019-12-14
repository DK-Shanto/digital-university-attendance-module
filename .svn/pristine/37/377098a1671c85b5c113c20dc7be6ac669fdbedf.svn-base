<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.cca.inc';
//include_once './common/class.common.course.php';


Class CCAMENUDAO{

	private $_DB;
	private $_category;
	private $ccaClass;
	private $_organizer;
	private $_ID;
	
	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_category = new Category();
		$this->ccaClass = new CCAMENU();
		$this->_organizer=new Organizer();
	}

	// get all the Schools from the database using the database query

	public function AddmenuCatagory($ADDCAT){

		$catagory=$ADDCAT->getCatagory();


		$SQL = "INSERT INTO tbl_category(categoryName) VALUES('$catagory') ";

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}
	public function updatecategory($ADDCAT){




		$SQL = "UPDATE tbl_category set categoryName='".$ADDCAT->getCatagory()."' WHERE cat_id='".$ADDCAT->getcatID()."'";

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}


public function CATDELETE($CCA){

		//beginning a transaction
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);

		//removing previous Positions

		$SQL_delete = "DELETE from tbl_category where cat_id ='".$CCA->getcatID()."'";
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




	public function readCAT($cca){


		$SQL = "SELECT *from tbl_category where cat_id='".$cca->getcatID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Role from the database
		$row = $this->_DB->getTopRow();

		$this->_Role = new CCAMENU();

		//preparing the Role object
	    $this->_Role->setCatagory ( $row['categoryName']);




	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Role);

		return $Result;
	}





public function getCATA(){

		$CategoryList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_category");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_category = new CCAMENU();
			$this->_category->setcatID($row['cat_id']);
		    $this->_category->setCatagory($row['categoryName']);
		    $CategoryList[]=$this->_category;

		}


		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CategoryList);

		return $Result;
	}




}



?>
