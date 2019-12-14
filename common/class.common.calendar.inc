<?php 
class AddEvent{
    
    private $_ID;
    private $_EventTitle;
    private $_EventDate;
    private $_eventStartTime;
    private $_eventEndTime;
    private $_Discipline;


    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setEventTitle( $EventTitle ) {
        $this->_EventTitle = $EventTitle;
    }

    public function getEventTitle() {
        return $this->_EventTitle;
    }

    public function setEventDate ( $EventDate ) {
        $this->_EventDate = $EventDate;
    }

    public function getEventDate () {
        return $this->_EventDate;
    }

    public function seteventStartTime ( $eventStartTime ) {
        $this->_eventStartTime = $eventStartTime;
    }

    public function geteventStartTime () {
        return $this->_eventStartTime;
    }

        public function seteventEndTime ( $eventEndTime ) {
        $this->_eventEndTime = $eventEndTime;
    }

    public function geteventEndTime () {
        return $this->_eventEndTime;
    }

    public function setDiscipline ( $Discipline ) {
        $this->_Discipline = $Discipline;
    }

    public function getDiscipline () {
        return $this->_Discipline;
    }
}

?>