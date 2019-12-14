<?php


class File{
    private $_ID;
    private $_Creator;
    private $_Link;
    private $_CurrentUser;

    /**
     * @return mixed
     */
    public function getID()
    {
        return $this->_ID;
    }

    /**
     * @param mixed $ID
     */
    public function setID($ID)
    {
        $this->_ID = $ID;
    }

    /**
     * @return mixed
     */
    public function getCreator()
    {
        return $this->_Creator;
    }

    /**
     * @param mixed $Creator
     */
    public function setCreator($Creator)
    {
        $this->_Creator = $Creator;
    }

    /**
     * @return mixed
     */
    public function getLink()
    {
        return $this->_Link;
    }

    /**
     * @param mixed $Link
     */
    public function setLink($Link)
    {
        $this->_Link = $Link;
    }

    /**
     * @return mixed
     */
    public function getCurrentUser()
    {
        return $this->_CurrentUser;
    }

    /**
     * @param mixed $CurrentUser
     */
    public function setCurrentUser($CurrentUser)
    {
        $this->_CurrentUser = $CurrentUser;
    }



}

class File_assign{
    private $_File;
    private $_FileComment;
    private $_sender;
    private $_receiver;
    private $_discipline;
    private $_timestamp;
    private $_links;

    /**
     * @return mixed
     */
    public function getLinks()
    {
        return $this->_links;
    }

    /**
     * @param mixed $links
     */
    public function setLinks($links)
    {
        $this->_links = $links;
    }









    /**
     * @return mixed
     */
    public function getFile()
    {
        return $this->_File;
    }

    /**
     * @param mixed $File
     */
    public function setFile($File)
    {
        $this->_File = $File;
    }

    /**
     * @return mixed
     */
    public function getFileComment()
    {
        return $this->_FileComment;
    }

    /**
     * @param mixed $FileComment
     */
    public function setFileComment($FileComment)
    {
        $this->_FileComment = $FileComment;
    }

    /**
     * @return mixed
     */
    public function getSender()
    {
        return $this->_sender;
    }

    /**
     * @param mixed $sender
     */
    public function setSender($sender)
    {
        $this->_sender = $sender;
    }

    /**
     * @return mixed
     */
    public function getReceiver()
    {
        return $this->_receiver;
    }

    /**
     * @param mixed $receiver
     */
    public function setReceiver($receiver)
    {
        $this->_receiver = $receiver;
    }

    /**
     * @return mixed
     */
    public function getDiscipline()
    {
        return $this->_discipline;
    }

    /**
     * @param mixed $discipline
     */
    public function setDiscipline($discipline)
    {
        $this->_discipline = $discipline;
    }

    /**
     * @return mixed
     */
    public function getTimestamp()
    {
        return $this->_timestamp;
    }

    /**
     * @param mixed $timestamp
     */
    public function setTimestamp($timestamp)
    {
        $this->_timestamp = $timestamp;
    }




}


?>