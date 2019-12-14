<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.cca.inc';
//include_once './common/class.common.course.php';

 //$CC=7;
// $n="";
Class CCADAO{

	private $_DB;
	private $_category;
	private $_organizer;
	private $ccaClass;
	private $_catid;
	private $_orgid;
	private $_CCA;


	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_category = new Category();
		$this->_organizer= new Organizer();
		$this->ccaClass = new CCA();

	}

	// get all the Schools from the database using the database query
	public function getAllCategory(){

		$CategoryList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_category");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_category = new Category();

		    $this->_category->setID ( $row['cat_id']);
		    $this->_category->setCategoryName( $row['categoryName'] );


		    $CategoryList[]=$this->_category;

		}


		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CategoryList);

		return $Result;
	}
	public function getAllCCA(){

		$CategoryList = array();

		$this->_DB->doQuery("SELECT * FROM mytable");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_category = new CCA();
					    $this->_category->setsrl($row['serial']);

		    $this->_category->setCat($row['category']);

		    $this->_category->setActivityName( $row['actName']);
		    		    $this->_category->setOrganizer($row['Organizer']);

		    $this->_category->setDescription( $row['description'] );
		    		    $this->_category->setVenu( $row['venu'] );

		    $this->_category->setDate( $row['date'] );

		    $this->_category->setTime( $row['time'] );


		    $CategoryList[]=$this->_category;

		}


		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CategoryList);

		return $Result;
	}



public function CCADELETE($CCA){

		//beginning a transaction
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);

		//removing previous Positions

		$SQL_delete = "DELETE from mytable where serial ='".$CCA->getsrl()."'";
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








	public function getAllOrganizer(){

		$CategoryList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_organizer");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_organizer = new Organizer();

		    $this->_organizer->setID ( $row['org_id']);
		    $this->_organizer->setOrganizerName( $row['organizerName'] );


		    $CategoryList[]=$this->_organizer;

		}


		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CategoryList);

		return $Result;
	}
	public function AddCatagory($ADDCAT){

		$ID=$ADDCAT->getCat();

		//$Name=$ADDCAT->getName();
		$ActivityName=$ADDCAT->getActivityName();
		$orga=$ADDCAT->getOrganizer();
		//$Organizer=$ADD->getOrganizer();
		$Venu=$ADDCAT->getVenu();
		$Description=$ADDCAT->getDescription();
		$Date=$ADDCAT->getDate();
		$time=$ADDCAT->getTime();

		$n=$ADDCAT->getOrganizer();



		$SQL = "INSERT INTO myTable(category,actName,Organizer,venu,description,date,time) VALUES('$ID','$ActivityName','$orga','$Venu','$Description','$Date','$time') ";

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}
	//Update


public function updatecat($ADDCAT){




		$SQL = "UPDATE myTable set category='".$ADDCAT->getCat()."',actName='".$ADDCAT->getActivityName()."',Organizer='".$ADDCAT->getOrganizer()."',venu='".$ADDCAT->getVenu()."',description='".$ADDCAT->getDescription()."', date='".$ADDCAT->getDate()."', time='".$ADDCAT->getTime()."' WHERE serial='".$ADDCAT->getsrl()."'";

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}


	//EDit
	public function readcca($cca){


		$SQL = "SELECT * FROM mytable WHERE serial='".$cca->getsrl()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Role from the database
		$row = $this->_DB->getTopRow();

		$this->_CCA = new CCA();

		//preparing the Role object
		 $this->_CCA->setsrl ( $row['serial']);
	    $this->_CCA->setCat ( $row['category']);
	    $this->_CCA->setActivityName( $row['actName'] );
	    $this->_CCA->setOrganizer( $row['Organizer']);
	     $this->_CCA->setVenu( $row['venu']);
	    $this->_CCA->setDescription( $row['description']);
	    $this->_CCA->setDate($row['date'] );
	    $this->_CCA->setTime($row['time']);



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_CCA);

		return $Result;
	}

	public function SearchEvent($query){
		$EventList = array();

		$this->_DB->doQuery($query);

		$rows = $this->_DB->getAllRows();
		echo "<table>
	<tr>
		<td>Category</td>
		<td>Activity</td>
		<td>Organizer</td>
		<td>venu</td>
		<td>Description</td>
		<td>Date</td>
		<td>Time</td>

	</tr>";
		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->ccaClass= new CCA();
			echo "<tr>";
			echo "<td>".CatNameFromID($row['catID'])."</td>";
			echo "<td> ".$row['actName']."</td>";
			echo "<td>".OrgNameFromID($row['orgID'])."</td>";
			//echo "<td> ".$row['Organizer']."</td>";
			echo "<td> ".$row['venu']."</td>";
			echo "<td> ".$row['description']."</td>";
			echo "<td>: ".$row['date']."</td>";
			echo "<td> ".$row['time']."</td>";
			echo "</tr>";

		}
		echo "</table>";
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject(1);

		return 1;
	}


}


?>
