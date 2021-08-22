<?php
class attendance
{
    private $_CourseNo;
    private $_Session;
    private $_Year;
    private $_Term;




    public function setCourseNo($CourseNo)
    {
        $this->_CourseNo = $CourseNo;
    }

    public function getCourseNo() {
        return $this->_CourseNo;
    }

    public function setSession( $Session)
    {
        $this->_Session = $Session;
    }

    public function getSession () {
        return $this->_Session;
    }

    public function setYear( $Year)
    {
        $this->_Year = $Year;
    }

    public function getYear () {
        return $this->_Year;
    }


    public function setTerm( $Term)
    {
        $this->_Term = $Term;
    }

    public function getTerm () {
        return $this->_Term;
    }
}
?>