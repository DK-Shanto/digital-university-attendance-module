<!--Thesiss Homepage-->
<?php
// write dao object for each class
include_once COMMON.'class.common.thesis.inc';
include_once UTILITY.'class.util.inc';

class ThesisHomeDao{

    private $_DB;
    private $_Thesis;

    public function __construct()
    {
        $this->_DB=DBUtil::getInstance();
        $this->_Thesis=new Thesis();
    }

    //get paginated thesis
    public function getLimitThesis($page,$limit){
        $ThesisList=array();
        $SQL="SELECT * FROM tms_thesis ORDER BY tms_thesis.created_at LIMIT $page,$limit";
        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();
        foreach ($rows as $row){
            $this->_Thesis=new Thesis();
            $this->_Thesis->setThesisId($row['id']);
            $this->_Thesis->setThesisThumbnail($row['thumbnail']);
            $this->_Thesis->setThesisTitle($row['title']);
            $this->_Thesis->setThesisDescription($row['description']);
            $this->_Thesis->setThesisPDFLink($row['pdf_link']);
            $this->_Thesis->setThesisYearId($row['year_id']);
            $this->_Thesis->setThesisTermId($row['term_id']);
            $this->_Thesis->setThesisCourseId($row['course_id']);
            $this->_Thesis->setThesisDisciplineId($row['discipline_id']);
            $this->_Thesis->setThesisCreatedAt($row['created_at']);
            $this->_Thesis->setThesisUpdatedAt($row['updated_at']);

            $ThesisList[]=$this->_Thesis;
        }

        
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($ThesisList);
        
        return $Result;
    }
    
}
?>
