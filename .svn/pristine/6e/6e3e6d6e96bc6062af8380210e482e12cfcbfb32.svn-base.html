<!--Search specific project-->
<?php
// write dao object for each class
include_once COMMON.'class.common.project.inc';
include_once UTILITY.'class.util.inc';

Class SearchProjectDao
{
    private $_DB;
    private $_Project;
    private $_Student;

    public function __construct()
    {
        $this->_DB=DBUtil::getInstance();
        $this->_Project=new Project();
        $this->_Student=new User();
    }

    //Get All Languages
    public function getAllLanguages(){
        $LanguageList=array();

        $SQL="SELECT DISTINCT pms_project.language FROM pms_project";
        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        foreach ($rows as $row) {
            $this->_Project=new Project();
            $this->_Project->setProjectLanguage($row['language']);

            $LanguageList[]=$this->_Project;
        }
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($LanguageList);

        return $Result;
    }

    //Get Searched Project
    public function getSearchedProject(){
        $Title=$Language=$YearId=$TermId=$CourseId=$DisciplineId=$TeacherId=$MemberId=$CreatedAt="";

        if (isset($_POST['title'])){
            $Title=$_POST['title'];
        }
        if (isset($_POST['language'])){
            $Language=$_POST['language'];
        }
        if (isset($_POST['year_id'])){
            $YearId=$_POST['year_id'];
        }
        if (isset($_POST['term_id'])){
            $TermId=$_POST['term_id'];
        }
        if (isset($_POST['course_id'])){
            $CourseId=$_POST['course_id'];
        }
        if (isset($_POST['discipline_id'])){
            $DisciplineId=$_POST['discipline_id'];
        }
        if (isset($_POST['teacher_id'])) {
            $TeacherId = $_POST['teacher_id'];
        }
        if (isset($_POST['member_id'])){
            $MemberId=$_POST['member_id'];
        }
        if (isset($_POST['created_at'])){
            $CreatedAt=$_POST['created_at'];
        }

        $ProjectList=array();

        if (isset($_POST['member_id'])&&!empty($_POST['member_id'])){
            $SQL="SELECT DISTINCT pms_project.id,pms_project.thumbnail,pms_project.title,pms_project.description,
                  pms_project.language,pms_project.year_id,pms_project.term_id,pms_project.course_id,pms_project.discipline_id,
                  pms_project.teacher_id,pms_project.created_at,pms_project.updated_at 
                  FROM pms_project INNER JOIN pms_student_project ON pms_project.id=pms_student_project.project_id WHERE pms_project.title LIKE '%$Title%' AND pms_project.language LIKE '%$Language%'
                  AND pms_project.year_id LIKE '%$YearId%' AND pms_project.term_id LIKE '%$TermId%' AND pms_project.course_id LIKE '%$CourseId%'
                  AND pms_project.discipline_id LIKE '%$DisciplineId%' AND pms_project.teacher_id LIKE '%$TeacherId%' AND pms_student_project.student_id LIKE '%$MemberId%'
                  AND pms_project.created_at LIKE '%$CreatedAt%'";
        }else{
            $SQL="SELECT DISTINCT pms_project.id,pms_project.thumbnail,pms_project.title,pms_project.description,
                  pms_project.language,pms_project.year_id,pms_project.term_id,pms_project.course_id,pms_project.discipline_id,
                  pms_project.teacher_id,pms_project.created_at,pms_project.updated_at 
                  FROM pms_project WHERE pms_project.title LIKE '%$Title%' AND pms_project.language LIKE '%$Language%'
                  AND pms_project.year_id LIKE '%$YearId%' AND pms_project.term_id LIKE '%$TermId%' AND pms_project.course_id LIKE '%$CourseId%'
                  AND pms_project.discipline_id LIKE '%$DisciplineId%' AND pms_project.teacher_id LIKE '%$TeacherId%' AND pms_project.created_at LIKE '%$CreatedAt%'";
        }

        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        foreach ($rows as $row) {
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
    
    public function getAllStudents(){
        $StudentList=array();
        $SQL="SELECT tbl_user.ID,tbl_user.Email,tbl_user.FirstName,tbl_user.LastName FROM tbl_user INNER JOIN tbl_user_role ON tbl_user.ID=tbl_user_role.UserID
              INNER JOIN tbl_role ON tbl_user_role.RoleID=tbl_role.ID WHERE tbl_role.Name='Student'";

        $this->_DB->doQuery($SQL);
        $rows=$this->_DB->getAllRows();

        foreach ($rows as $row) {
            $this->_Student=new User();
            $this->_Student->setID($row['ID']);
            $this->_Student->setEmail($row['Email']);
            $this->_Student->setFirstName($row['FirstName']);
            $this->_Student->setLastName($row['LastName']);

            $StudentList[]=$this->_Student;
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($StudentList);
        
        return $Result;
    }
    

}
?>
