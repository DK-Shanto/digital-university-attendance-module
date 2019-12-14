<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once COMMON.'class.common.book.inc';
include_once COMMON.'class.common.user.inc';

Class BookListDAO{

	private $_DB;
	private $_Book;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Book = new Book();
	}

	// get all the users from the database using the database query
	public function getAllBook(){

		$BookList = array();

		$this->_DB->doQuery("SELECT * FROM bsms_book ORDER BY date DESC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Book = new Book();
				$this->_Book->setBookID ( $row['id']);
				$this->_Book->setUserName ( $row['user_name']);
		    $this->_Book->setUserID ( $row['user_id']);
		    $this->_Book->setTitle ( $row['name'] );
		    $this->_Book->setEdition ( $row['edition'] );
		    $this->_Book->setWritter( $row['writter'] );
				$this->_Book->setDescription( $row['description'] );
		    $this->_Book->setAmmount( $row['ammount'] );
		    $this->_Book->setContactNumber( $row['contact_number'] );
		    $this->_Book->setDate( $row['date'] );
				$this->_Book->setImageName($row['img_name']);
				$this->_Book->setImage($row['img']);
			  //echo '<img src="data:image;base64,'.base64_encode($row['img']).' ">';
		    $BookList[]=$this->_Book;

		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($BookList);

		return $Result;
	}
	public function readBookPositions($Book)
	{
		$this->_DB->doQuery("SELECT * FROM bsms_book WHERE id like '".$Book->getBookID()."'");
		$rows = $this->_DB->getAllRows();
		$row = $rows[0];
		$this->_Book = new Book();
		//echo "".$row['name']."";
		$this->_Book->setBookID($row['id']);

		$this->_Book->setTitle($row['name']);

		$this->_Book->setEdition($row['edition']);

		$this->_Book->setWritter($row['writter']);

		$this->_Book->setDescription($row['description']);

		$this->_Book->setAmmount($row['ammount']);

		$this->_Book->setContactNumber($row['contact_number']);
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Book);
		return $Result;
	}
	public function deleteBook($Book)
	{

		$ID=$Book->getBookID();

		$SQL_delete = "DELETE FROM bsms_book WHERE ID LIKE '$ID'";
		//beginning a transaction
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		$SQL_delete = $this->_DB->doQuery($SQL_delete);
		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Book Deleted Successfully.");

		return $Result;

	}
	public function updateBookRequest($Book)
	{
		$ID = $Book->getBookID();
		$Title = $Book->getTitle();
		$Edition = $Book->getEdition();
		$Writter = $Book->getWritter();
		$Description = $Book->getDescription();
		$Ammount = $Book->getAmmount();
		$ContactNumber = $Book->getContactNumber();
		//echo $Title." ".$Edition." ".$ID;
		$SQL = "UPDATE bsms_book SET name='$Title',edition='$Edition',writter='$Writter',description='$Description',ammount='$Ammount',contact_number='$ContactNumber' WHERE id = '$ID'";

		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		$SQL = $this->_DB->doQuery($SQL);
		$this->_DB->getConnection()->commit();
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("Update Book Request Submitted Successfully.");

		return $Result;

	}
}

?>
