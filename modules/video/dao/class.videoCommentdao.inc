<?php
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.video.inc';
include_once UTILITY.'class.util.inc';

Class VideoCommentDAO{

	private $_DB;
	private $_Cat;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Cat = new VideoComment();

	}



	// get all the VideoComments from the database using the database query
	public function getAllVideoComments(){

		$VideoCommentList = array();

		$this->_DB->doQuery("SELECT * FROM vtms_video_comment");
		$rows = $this->_DB->getAllRows();


		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_VideoComment = new VideoComment();

		    $this->_VideoComment->setCommentID ( $row['CommentID']);
		    $this->_VideoComment->setComment( $row['Comment'] );
		    $this->_VideoComment->setCreatorID( $row['CreatorID'] );
		    $this->_VideoComment->setVideo( $row['VideoID'] );
		    
		    $this->_VideoComment->setCommentIDTop($row['CommentIDTop']);
		    $this->_VideoComment->setCreationDate($row['CreationDate']);

		    $VideoCommentList[]=$this->_VideoComment;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($VideoCommentList);

		return $Result;
	}

	//create VideoComment funtion with the VideoComment object
	public function createVideoComment($VideoComment){
		// var_dump($VideoComment);
		$VideoCommentID=$VideoComment->getCommentID();
		
		$VideoComment2=$VideoComment->getComment();
		$CreatorID=$VideoComment->getCreatorID();
		$VideoID=$VideoComment->getVideoID();
		
		$CommentIDTop=$VideoComment->getCommentIDTop();

		$SQL = "INSERT INTO vtms_video_comment(CommentID,Comment,CreatorID,VideoID,CommentIDTop,CreationDate) 
				VALUES('$VideoCommentID','$VideoComment2','$CreatorID','$VideoID','$CommentIDTop',now())";

		//echo $SQL;
		//var_dump($SQL);

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}




	public function readCreator($CreatorID){

		$SQL = "SELECT * FROM ums_user
				WHERE ID ='".$CreatorID."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_useradd = new User();

		$this->_useradd->setID ( $row['ID']);
		$this->_useradd->setUniversityID( $row['UniversityID'] );
		$this->_useradd->setEmail ( $row['Email']);
		$this->_useradd->setPassword( $row['Password'] );
		$this->_useradd->setFirstName ( $row['FirstName']);
		$this->_useradd->setLastName( $row['LastName'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_useradd);

		return $Result;
	}
	
	public function readvideo($video){
		
		//$Dis = $video->getID();
		$SQL = "SELECT * FROM vtms_video WHERE ID='".$video."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this video from the database
		$row = $this->_DB->getTopRow();

		$this->_Video= new Video();

		//preparing the video object
	    $this->_Video->setID ( $row['ID']);
		$this->_Video->setTitle( $row['Title'] );
		$this->_Video->setDescription( $row['Description'] );
	    $this->_Video->setLink( $row['Link'] );
	    $this->_Video->setIsEmbed( $row['IsEmbed'] );
	    $this->_Video->setTag( $row['TagID'] );
	    $this->_Video->setCreatorID($row['CreatorID']);
		$this->_Video->setCreationDate($row['CreationDate']);



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Video);

		return $Result;
	}

	//read an VideoComment object based on its id form VideoComment object
	public function readVideoComment($video){
		$i='0';
		
		$VideoCommentList = array();

		$this->_DB->doQuery("SELECT CommentID,Comment,CreatorID,VideoID,CommentIDTop, CreationDate FROM vtms_video_comment  WHERE VideoID = '".$video."' AND CommentIDTop = '".$i."' ORDER BY CreationDate DESC ");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_VideoComment = new VideoComment();

		    $this->_VideoComment->setCommentID ( $row['CommentID']);
		    $this->_VideoComment->setVideoID( $row['VideoID'] );
		    $this->_VideoComment->setComment( $row['Comment'] );
		    $this->_VideoComment->setCreatorID( $row['CreatorID'] );
		   	$this->_VideoComment->setCreationDate($row['CreationDate']);
		    $this->_VideoComment->setCommentIDTop($row['CommentIDTop']);


		    $VideoCommentList[]=$this->_VideoComment;
   
		}


$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($VideoCommentList);

		return $Result;
	}
//read an Reply object based on its id form VideoComment object
	public function readVideoReply($Video){
		
		$VideoCommentList = array();

		$this->_DB->doQuery("SELECT * FROM vtms_video_comment WHERE CommentIDTop = '".$Video."' ");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_VideoComment = new VideoComment();

		    $this->_VideoComment->setCommentID ( $row['CommentID']);
		    $this->_VideoComment->setVideoID( $row['VideoID'] );
		    $this->_VideoComment->setComment( $row['Comment'] );
		    $this->_VideoComment->setCreatorID( $row['CreatorID'] );
		   	$this->_VideoComment->setCreationDate( $row['CreationDate'] );
		    $this->_VideoComment->setCommentIDTop($row['CommentIDTop']);


		    $VideoCommentList[]=$this->_VideoComment;
   
		}


		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($VideoCommentList);

		return $Result;
	}

	//update an VideoComment object based on its 
	public function updateVideoComment($VideoComment){

		$SQL = "UPDATE vtms_video_comment SET VideoComment='".$VideoComment->getVideoComment()."'
				WHERE CommentID='".$VideoComment->getCommentID()."'";

		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}


	public function updateViews($VideoID){
		$one=1;

		$SQL = "UPDATE vtms_video SET Views = Views + ".$one."
where ID = '".$VideoID."'";
	var_dump($SQL);

		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	
	public function relatedVideo($tag,$id,$title){

		$VideoList = array();

		$this->_DB->doQuery("SELECT * FROM vtms_video WHERE  (TagID like '%$tag%' OR Title like '%$title%') AND  ID <> '$id' ORDER BY CreationDate DESC ");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];

			$this->_Video = new Video();

		    $this->_Video->setID ( $row['ID']);
		    $this->_Video->setTitle( $row['Title'] );
		    $this->_Video->setDescription( $row['Description'] );
		    $this->_Video->setLink( $row['Link'] );
		    $this->_Video->setIsEmbed( $row['IsEmbed'] );
		    $this->_Video->setTag( $row['TagID'] );
		    $this->_Video->setCreatorID( $row['CreatorID'] );
		    $this->_Video->setCreationDate( $row['CreationDate'] );

		    
		    $VideoList[]=$this->_Video;
   
		}	
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($VideoList);

		return $Result;
	}	


	//delete an VideoComment based on its id of the database
	public function deleteVideoComment($VideoComment){


		$SQL = "DELETE from vtms_video_comment where CommentID ='".$VideoComment->getCommentID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

////$_Log->log(LogUtil::$DEBUG," exit the class.videoCommentdao.inc");

?>

