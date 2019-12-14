
<?php

class Video{
    
    private $_ID;
    private $_Title;
    private $_Description;
    private $_Link;
    private $_IsEmbed;
    private $_EmbedLink;
    private $_CreationDate;
    private $_Creator;
    private $_Tag;
    private $_Views;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setTitle( $Title ) {
        $this->_Title = $Title;
    }

    public function getTitle() {
        return $this->_Title;
    }


    public function setCreatorID ( $Creator ) {
        $this->_Creator = $Creator;
    }

    public function getCreatorID () {
        return $this->_Creator;
    }
    
    public function setDescription ( $Description) {
        $this->_Description = $Description;
    }

    public function getDescription() {
        return $this->_Description;
    }


    public function setLink( $Link ) {
        $this->_Link = $Link;
    }

    public function getLink() {
        return $this->_Link;
    }


    public function setIsEmbed ( $IsEmbed ) {
        $this->_IsEmbed = $IsEmbed;
    }

    public function getIsEmbed () {
        return $this->_IsEmbed;
    }


    public function setEmbedLink( $EmbedLink ) {
        $this->_EmbedLink = $EmbedLink;
    }

    public function getEmbedLink() {
        return $this->_EmbedLink;
    }

    public function setCreationDate( $CreationDate ) {
        $this->_CreationDate = $CreationDate;
    }

    public function getCreationDate() {
        return $this->_CreationDate;
    }

    
    public function setTag( $Tag ) {
        $this->_Tag = $Tag;
    }

    public function getTag() {
        return $this->_Tag;
    }
    public function setViews ( $Views ) {
        $this->_Views = $Views;
    }

    public function getViews () {
        return $this->_Views;
    }

}

class VideoComment{
    
    private $_CommentID;
    private $_Comment;
    private $_Creator;
    private $_VideoID;
    
    private $_CommentIDTop;
    private $_CreationDate;

    public function setCommentID ( $CommentID ) {
        $this->_CommentID = $CommentID;
    }

    public function getCommentID () {
        return $this->_CommentID;
    }


    public function setComment( $Comment ) {
        $this->_Comment = $Comment;
    }

    public function getComment() {
        return $this->_Comment;
    }


    public function setCreatorID ( $Creator ) {
        $this->_Creator = $Creator;
    }

    public function getCreatorID () {
        return $this->_Creator;
    }



    public function setVideoID( $VideoID ) {
        $this->_VideoID = $VideoID;
    }

    public function getVideoID() {
        return $this->_VideoID;
    }

    public function setIsReply ( $IsReply ) {
        $this->_IsReply = $IsReply;
    }

    public function getIsReply () {
        return $this->_IsReply;
    }
    public function setCommentIDTop ( $CommentIDTop ) {
        $this->_CommentIDTop = $CommentIDTop;
    }

    public function getCommentIDTop () {
        return $this->_CommentIDTop;
    }
    public function setCreationDate( $CreationDate ) {
        $this->_CreationDate = $CreationDate;
    }

    public function getCreationDate() {
        return $this->_CreationDate;
    }    

}



class VideoTag{
    
    private $_Video;
    private $_Tag;

    public function setVideo ( $Video ) {
        $this->_Video = $Video;
    }

    public function getVideo () {
        return $this->_Video;
    }


    public function setTag( $Tag ) {
        $this->_Tag = $Tag;
    }

    public function getTag() {
        return $this->_Tag;
    }

}



?>