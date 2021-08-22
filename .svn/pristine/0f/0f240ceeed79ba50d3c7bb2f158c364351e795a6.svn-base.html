<!--Search specific thesis-->
<?php
// write dao object for each class
include_once COMMON.'class.common.thesis.inc';
include_once UTILITY.'class.util.inc';

Class SearchThesisDao
{
    private $_DB;
    private $_Thesis;
    private $_Student;

    public function __construct()
    {
        $this->_DB=DBUtil::getInstance();
        $this->_Thesis=new Thesis();
        $this->_Student=new User();
    }

    //Get Searched Thesis
    public function getSearchedThesis(){
        $Title=$YearId=$TermId=$CourseId=$DisciplineId=$TeacherId=$MemberId=$CreatedAt="";

        if (isset($_POST['title'])){
            $Title=$_POST['title'];
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

        $ThesisList=array();

        if (isset($_POST['member_id'])&&!empty($_POST['member_id'])&&isset($_POST['teacher_id'])&&!empty($_POST['teacher_id'])){
            $SQL="SELECT DISTINCT tms_thesis.id,tms_thesis.thumbnail,tms_thesis.title,tms_thesis.description,tms_thesis.pdf_link,
                  tms_thesis.year_id,tms_thesis.term_id,tms_thesis.course_id,tms_thesis.discipline_id,
                  tms_thesis.created_at,tms_thesis.updated_at 
                  FROM tms_thesis INNER JOIN tms_student_thesis ON tms_thesis.id=tms_student_thesis.thesis_id INNER JOIN tms_supervisor_thesis ON
                  tms_thesis.id=tms_supervisor_thesis.thesis_id WHERE tms_thesis.title LIKE '%$Title%'
                  AND tms_thesis.year_id LIKE '%$YearId%' AND tms_thesis.term_id LIKE '%$TermId%' AND tms_thesis.course_id LIKE '%$CourseId%'
                  AND tms_thesis.discipline_id LIKE '%$DisciplineId%' AND tms_supervisor_thesis.supervisor_id LIKE '%$TeacherId%' AND tms_student_thesis.student_id LIKE '%$MemberId%'
                  AND tms_thesis.created_at LIKE '%$CreatedAt%'";

        }elseif (isset($_POST['member_id'])&&!empty($_POST['member_id'])) {
            $SQL="SELECT DISTINCT tms_thesis.id,tms_thesis.thumbnail,tms_thesis.title,tms_thesis.description,tms_thesis.pdf_link,
                  tms_thesis.year_id,tms_thesis.term_id,tms_thesis.course_id,tms_thesis.discipline_id,
                  tms_thesis.created_at,tms_thesis.updated_at 
                  FROM tms_thesis INNER JOIN tms_student_thesis ON tms_thesis.id=tms_student_thesis.thesis_id WHERE tms_thesis.title LIKE '%$Title%'
                  AND tms_thesis.year_id LIKE '%$YearId%' AND tms_thesis.term_id LIKE '%$TermId%' AND tms_thesis.course_id LIKE '%$CourseId%'
                  AND tms_thesis.discipline_id LIKE '%$DisciplineId%' AND tms_student_thesis.student_id LIKE '%$MemberId%'
                  AND tms_thesis.created_at LIKE '%$CreatedAt%'";

        }elseif (isset($_POST['teacher_id'])&&!empty($_POST['teacher_id'])) {
            $SQL="SELECT DISTINCT tms_thesis.id,tms_thesis.thumbnail,tms_thesis.title,tms_thesis.description,tms_thesis.pdf_link,
                  tms_thesis.year_id,tms_thesis.term_id,tms_thesis.course_id,tms_thesis.discipline_id,
                  tms_thesis.created_at,tms_thesis.updated_at 
                  FROM tms_thesis INNER JOIN tms_supervisor_thesis ON tms_thesis.id=tms_supervisor_thesis.thesis_id WHERE tms_thesis.title LIKE '%$Title%'
                  AND tms_thesis.year_id LIKE '%$YearId%' AND tms_thesis.term_id LIKE '%$TermId%' AND tms_thesis.course_id LIKE '%$CourseId%'
                  AND tms_thesis.discipline_id LIKE '%$DisciplineId%' AND tms_supervisor_thesis.supervisor_id LIKE '%$TeacherId%'
                  AND tms_thesis.created_at LIKE '%$CreatedAt%'";

        }else{
            $SQL="SELECT DISTINCT tms_thesis.id,tms_thesis.thumbnail,tms_thesis.title,tms_thesis.description,tms_thesis.pdf_link,
                  tms_thesis.year_id,tms_thesis.term_id,tms_thesis.course_id,tms_thesis.discipline_id,
                  tms_thesis.created_at,tms_thesis.updated_at 
                  FROM tms_thesis WHERE tms_thesis.title LIKE '%$Title%' AND tms_thesis.year_id LIKE '%$YearId%' 
                  AND tms_thesis.term_id LIKE '%$TermId%' AND tms_thesis.course_id LIKE '%$CourseId%'
                  AND tms_thesis.discipline_id LIKE '%$DisciplineId%' AND tms_thesis.created_at LIKE '%$CreatedAt%'";
        }

        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        foreach ($rows as $row) {
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
    
    public function getAllStudents(){
        $StudentList=array();
        $SQL="SELECT ums_user.ID,ums_user.Email,ums_user.FirstName,ums_user.LastName FROM ums_user INNER JOIN ums_user_role ON ums_user.ID=ums_user_role.UserID
              INNER JOIN ums_role ON ums_user_role.RoleID=ums_role.ID WHERE ums_role.Name='Student'";

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
