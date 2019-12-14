<!--Projects Homepage-->
<?php
// write dao object for each class
include_once COMMON.'class.common.project.inc';
include_once UTILITY.'class.util.inc';

class ProjectHomeDao{

    private $_DB;
    private $_Project;

    public function __construct()
    {
        $this->_DB=DBUtil::getInstance();
        $this->_Project=new Project();
    }

    //get paginated projects
    public function getLimitProject($page,$limit){
        $ProjectList=array();
        $SQL="SELECT * FROM pms_project ORDER BY pms_project.created_at LIMIT $page,$limit";
        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();
        foreach ($rows as $row){
            $this->_Project=new Project();
            $this->_Project->setProjectId($row['id']);
            $this->_Project->setProjectThumbnail($row['thumbnail']);
            $this->_Project->setProjectTitle($row['title']);
            $this->_Project->setProjectDescription($row['description']);
            $this->_Project->setProjectLanguage($row['language']);
            $this->_Project->setProjectYearId($row['year_id']);
            $this->_Project->setProjectTermId($row['term_id']);
            $this->_Project->setProjectCourseId($row['course_id']);
            $this->_Project->setProjectDisciplineId($row['discipline_id']);
            $this->_Project->setProjectTeacherId($row['teacher_id']);
            $this->_Project->setProjectCreatedAt($row['created_at']);
            $this->_Project->setProjectUpdatedAt($row['updated_at']);

            $ProjectList[]=$this->_Project;
        }

        
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($ProjectList);
        
        return $Result;
    }
    
}
?>
