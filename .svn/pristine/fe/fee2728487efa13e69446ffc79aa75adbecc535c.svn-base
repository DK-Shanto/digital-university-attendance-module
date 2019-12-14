<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.cca.inc';
//include_once './common/class.common.course.php';


Class CCAUSERDAO{

	private $_DB;
	private $_category;
	private $ccauserClass;
	private $_organizer;
	
	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_category = new Category();
		$this->_organizer=new Organizer();
		$this->ccauserClass = new CCAUSER();

	}

	// get all the Schools from the database using the database query
	public function getCategories(){

		$CategoryList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_category");

		$rows = $this->_DB->getAllRows();

		for($i =0; $i < sizeof($rows); $i++) {
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
	//Get all Catagories from database
	public function getOrganizers(){

		$CategoryList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_organizer");

		$rows = $this->_DB->getAllRows();

		for($i =0; $i < sizeof($rows); $i++) {
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

		$ID=$ADDCAT->getID();

		//$Name=$ADDCAT->getName();
		$ActivityName=$ADDCAT->getActivityName();
		$orga=$ADDCAT->getOrganizer();
		//$Organizer=$ADD->getOrganizer();
		$Venu=$ADDCAT->getVenu();
		$Description=$ADDCAT->getDescription();
		$Date=$ADDCAT->getDate();
		$time=$ADDCAT->getTime();





		$SQL = "INSERT INTO myTable(cat_id,actName,Organizer,venu,description,date,time) VALUES('$ID','$ActivityName','$orga','$Venu','$Description','$Date','$time') ";

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}
	public function Adddetails($ADD){

		$ID=$ADD->getID();
		$ActivityName=$ADD->getActivityName();
		$Organizer=$ADD->getOrganizer();
		$Venu=$ADD->getVenu();
		$Description=$ADD->getDescription();




		$SQL = "INSERT INTO activity_type(cat_id,activityName,Organizer,venu,description) VALUES('$ID','$ActivityName','$Organizer','$Venu','$Description')";

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	public function SearchEvent($query){
		$EventList = array();

		$this->_DB->doQuery($query);

		$rows = $this->_DB->getAllRows();

		?>

		<div>  <center><h2> Events </h2></center></div>
		<?php

		for($i = 0; $i < sizeof($rows); $i++) {
?>

			<table style="width:900px;height: 100% ;margin-left: 100px; border: 1px ;">

				<?php
			$row = $rows[$i];
			$this->ccauserClass= new CCAUSER();
			echo "<tr>";
			?>
			<tr><td style="width:130px; font-weight: bolder;"> Catagory Name </td>	<td style="padding-left: 20px;"><?php echo $row['category'];?> </td>	</tr>
			<tr><td style="width:130px; font-weight: bolder;"> Activity Name </td>	<td style="padding-left: 20px;"><?php echo $row['actName'];?> </td>		</tr>
			<tr><td style="width:130px; font-weight: bolder;"> Organizer </td>	<td style="padding-left: 20px;"><?php echo $row['Organizer'];?> </td>	</tr>
			<tr><td style="width:130px; font-weight: bolder;"> Venu</td>	<td style="padding-left: 20px;"><?php echo $row['venu'];?> </td>	</tr>
			<tr><td style="width:130px; font-weight: bolder;">Description</td>	<td style="padding-left: 20px;"><?php echo $row['description'];?></td>	 </tr>
			<tr><td style="width:130px; font-weight: bolder;">Date</td>	<td style="padding-left: 20px;"><?php echo $row['date'];?></td>		 </tr>
			<tr><td style="width:130px; font-weight: bolder;">Time</td>	<td style="padding-left: 20px;"><?php echo $row['time'];?></td> 	</tr>
			<br><br>

       </table>


       <?php


		}
		echo "</table>";

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject(1);

		return 1;
	}

	public function SearchEvent1($query){
		$EventList = array();

		$this->_DB->doQuery($query);

		$rows = $this->_DB->getAllRows();

		?>
		<br>
		<br>
		<div>  <center><h2> Previous / Completed  Events</h2></center></div>
		<?php

		for($i = 0; $i < sizeof($rows); $i++) {
?>

			<table style="width:900px;height: 100% ;margin-left: 100px; border: 100px ;color: blue;">

				<?php
			$row = $rows[$i];
			$this->ccauserClass= new CCAUSER();
			echo "<tr>";
			?>
			<tr><td style="width:130px; font-weight: bolder;"> Catagory Name </td>	<td style="padding-left: 20px;"><?php echo $row['category'];?> </td>	</tr>
			<tr><td style="width:130px; font-weight: bolder;"> Activity Name </td>	<td style="padding-left: 20px;"><?php echo $row['actName'];?> </td>		</tr>
			<tr><td style="width:130px; font-weight: bolder;"> Organizer </td>	<td style="padding-left: 20px;"><?php echo $row['Organizer'];?> </td>	</tr>
			<tr><td style="width:130px; font-weight: bolder;"> Venu</td>	<td style="padding-left: 20px;"><?php echo $row['venu'];?> </td>	</tr>
			<tr><td style="width:130px; font-weight: bolder;">Description</td>	<td style="padding-left: 20px;"><?php echo $row['description'];?></td>	 </tr>
			<tr><td style="width:130px; font-weight: bolder;">Date</td>	<td style="padding-left: 20px;"><?php echo $row['date'];?></td>		 </tr>
			<tr><td style="width:130px; font-weight: bolder;">Time</td>	<td style="padding-left: 20px;"><?php echo $row['time'];?></td> 	</tr>
			<br><br>

       </table>


       <?php


		}
		echo "</table>";

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject(1);

		return 1;
	}


}

?>
