<!--Project CRUD-->
<?php
// write dao object for each class
include_once COMMON.'class.common.project.inc';
include_once UTILITY.'class.util.inc';

Class ProjectDao
{

    private $_DB;
    private $_Project;
    private $_Year;
    private $_Term;
    private $_Course;
    private $_Discipline;
    private $_Teacher;

    function __construct()
    {

        $this->_DB = DBUtil::getInstance();
        $this->_Project = new Project();
        $this->_Year=new Year();
        $this->_Term=new Term();
        $this->_Course=new Course();
        $this->_Teacher=new User();
    }

    //create new project
    public function createProject($Project){

        $ID=$Project->getProjectId();
        $Thumbnail=$Project->getProjectThumbnail();
        $Title=$Project->getProjectTitle();
        $Description=$Project->getProjectDescription();
        $Language=$Project->getProjectLanguage();
        $YearId=$Project->getProjectYearId();
        $TermId=$Project->getProjectTermId();
        $CourseId=$Project->getProjectCourseId();
        $DisciplineId=$Project->getProjectDisciplineId();
        $TeacherId=$Project->getProjectTeacherId();

        $SQL = "INSERT INTO pms_project VALUES('$ID','$Thumbnail','$Title','$Description','$Language','$YearId','$TermId','$CourseId','$DisciplineId',
        '$TeacherId',CURRENT_TIMESTAMP ,CURRENT_TIMESTAMP )";

        $SQL = $this->_DB->doQuery($SQL);

        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }

    //upload project thumbnails
    public function uploadThumbnail($Project)
    {
        $target_dir = './resources/img/thumbnails/';
        $target_file = $target_dir . basename($_FILES['thumbnail']['name']);
        $fileType = pathinfo($target_file, PATHINFO_EXTENSION);
        if (!empty($_FILES['thumbnail']['tmp_name'])) {
            $size = getimagesize($_FILES['thumbnail']['tmp_name']);
            $uploaded = 1;

            if ($size !== false) {
                echo 'File is an image - '.$size['mime'].'.';
                $uploaded = 1;
            } else {
                echo '<br>File is not an image';
                $uploaded = 0;
            }

            if (file_exists($target_file)) {
                echo '<br>Sorry, file already exists';
                $uploaded = 0;
            }

            if ($_FILES['thumbnail']['size'] > 50000000) {
                echo '<br>Sorry, your file is too large';
             $uploaded = 0;
            }

            if ($fileType != 'jpg' && $fileType != 'png' && $fileType != 'jpeg' && $fileType != 'ico') {
                echo '<br>Sorry, only jpg, jpeg, png & ico files are allowed';
                $uploaded = 0;
            }
            // Check if $uploadOk is set to 0 by an error
            if ($uploaded == 0) {
                echo "<br>Sorry, your file was not uploaded.";
                // if everything is ok, try to upload file
            } else {
                if(isset($_POST['update'])){
                    $del_dir=$_POST['thumbnailsrc'];
                    unlink($del_dir);
                }
                if (move_uploaded_file($_FILES["thumbnail"]["tmp_name"], $target_dir.$Project->getProjectTitle().'.'.$fileType)) {
                    $Upload = array();
                    //returns a boolean value
                    $Upload['uploaded'] = $uploaded;
                    //returns the directory of the uploaded file
                    $Upload['target_file'] = $target_dir.$Project->getProjectTitle().'.'.$fileType;
                    return $Upload;
                } else {
                    echo "<br>Sorry, there was an error uploading your file.";
                }
            }
        } else {
            if (!isset($_POST['update'])){
                echo "<br>Cannot upload the image.<br>Check image size.";
            }else{
                $Upload['uploaded']=1;
                $Upload['target_file']=$_POST['thumbnailsrc'];
                return $Upload;
            }
        }
    }

    //delete project thumbnail
    public function deleteThumbnail($Project){
        $del_dir=$Project->getProjectThumbnail();
        unlink($del_dir);

        return true;
    }

    //get All projects
    public function getAllProjects(){
        $ProjectList=array();

        $SQL="SELECT * FROM pms_project ORDER BY pms_project.created_at";
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

        //todo: LOG util with level of log


        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($ProjectList);

        return $Result;

    }

    //Get All Years
    public function getAllYears(){
        $YearList=array();

        $SQL="SELECT * FROM reg_year";
        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        foreach ($rows as $row){

            $this->_Year=new Year();
            $this->_Year->setID($row['ID']);
            $this->_Year->setName($row['Name']);

            $YearList[]=$this->_Year;
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($YearList);

        return $Result;
    }

    //get All Terms
    public function getAllTerms(){
        $TermList=array();

        $SQL="SELECT * FROM reg_term";
        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();
        foreach ($rows as $row){
            $this->_Term=new Term();
            $this->_Term->setID($row['ID']);
            $this->_Term->setName($row['Name']);

            $TermList[]=$this->_Term;
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($TermList);

        return $Result;
    }

    //get All Courses
    public function getAllCourses(){
        $CourseList=array();

        $SQL="SELECT * FROM reg_course";
        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();
        foreach ($rows as $row){
            $this->_Course=new Course();
            $this->_Course->setID($row['ID']);
            $this->_Course->setCourseNo($row['CourseNo']);
            $this->_Course->setTitle($row['Title']);
            $this->_Course->setCredit($row['Credit']);
            $this->_Course->setCourseTypeID($row['CourseTypeID']);
            $this->_Course->setDisciplineID($row['DisciplineID']);
            $this->_Course->setISDeleted($row['IsDeleted']);

            $CourseList[]=$this->_Course;
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($CourseList);

        return $Result;
    }

    //get All Discipline
    public function getAllDisciplines(){
        $DisciplineList=array();

        $SQL="SELECT * FROM ums_discipline";
        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();
        foreach ($rows as $row){
            $this->_Discipline=new Discipline();
            $this->_Discipline->setID($row['ID']);
            $this->_Discipline->setName($row['Name']);
            $this->_Discipline->setShortCode($row['ShortCode']);
            $this->_Discipline->setSchool($row['SchoolID']);

            $DisciplineList[]=$this->_Discipline;
        }
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($DisciplineList);

        return $Result;
    }

    //get All Teachers
    public function getAllTeachers(){
        $TeacherList=array();

        $SQL="SELECT ums_user.ID,ums_user.FirstName,ums_user.LastName FROM ums_user 
        INNER JOIN ums_user_role ON ums_user.ID=ums_user_role.UserID INNER JOIN ums_role ON ums_user_role.RoleID=ums_role.ID 
        WHERE ums_role.Name='Teacher'";

        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();
        foreach ($rows as $row) {
            $this->_Teacher=new User();
            $this->_Teacher->setID($row['ID']);
            $this->_Teacher->setFirstName($row['FirstName']);
            $this->_Teacher->setLastName($row['LastName']);

            $TeacherList[]=$this->_Teacher;
        }
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($TeacherList);

        return $Result;
    }

    //get specific year
    public function getYear($Year){
        $SQL="SELECT * FROM reg_year WHERE reg_year.ID='".$Year."'";
        $this->_DB->doQuery($SQL);

        $row=$this->_DB->getTopRow();
        $this->_Year=new Year();
        $this->_Year->setID($row['ID']);
        $this->_Year->setName($row['Name']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Year);
        
        return $Result;
    }

    //get specific term
    public function getTerm($Term){
        $SQL="SELECT * FROM reg_term WHERE reg_term.ID='".$Term."'";
        $this->_DB->doQuery($SQL);

        $row=$this->_DB->getTopRow();
        $this->_Term=new Term();
        $this->_Term->setID($row['ID']);
        $this->_Term->setName($row['Name']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Term);

        return $Result;
    }

    //get specific course
    public function getCourse($Course){
        $SQL="SELECT * FROM reg_course WHERE reg_course.ID='".$Course."'";
        $this->_DB->doQuery($SQL);

        $row=$this->_DB->getTopRow();
        $this->_Course=new Course();
        $this->_Course->setID($row['ID']);
        $this->_Course->setCourseNo($row['CourseNo']);
        $this->_Course->setTitle($row['Title']);
        $this->_Course->setCredit($row['Credit']);
        $this->_Course->setCourseTypeID($row['CourseTypeID']);
        $this->_Course->setDisciplineID($row['DisciplineID']);
        $this->_Course->setISDeleted($row['IsDeleted']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Course);

        return $Result;
    }
    
    //get specific Discipline
    public function getDiscipline($Discipline){
        $SQL="SELECT * FROM ums_discipline WHERE ums_discipline.ID='".$Discipline."'";
        $this->_DB->doQuery($SQL);

        $row=$this->_DB->getTopRow();
        $this->_Discipline=new Discipline();
        $this->_Discipline->setID($row['ID']);
        $this->_Discipline->setName($row['Name']);
        $this->_Discipline->setShortCode($row['ShortCode']);
        $this->_Discipline->setSchool($row['SchoolID']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Discipline);

        return $Result;
    }
 
    //get specific Teacher
    public function getTeacher($Teacher){
        $SQL="SELECT ums_user.ID, ums_user.FirstName,ums_user.LastName FROM ums_user 
        INNER JOIN ums_user_role ON ums_user.ID=ums_user_role.UserID INNER JOIN ums_role ON ums_user_role.RoleID=ums_role.ID 
        WHERE ums_role.Name='Teacher' AND ums_user.ID='".$Teacher."'";

        $this->_DB->doQuery($SQL);

        $row=$this->_DB->getTopRow();
        $this->_Teacher=new User();
        $this->_Teacher->setID($row['ID']);
        $this->_Teacher->setFirstName($row['FirstName']);
        $this->_Teacher->setLastName($row['LastName']);
        
        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Teacher);
        
        return $Result;
    }
    
    //get specific project
    public function getProject($Project){

        $SQL="SELECT * FROM pms_project WHERE pms_project.id='".$Project->getProjectId()."'";
        $this->_DB->doQuery($SQL);

        $row=$this->_DB->getTopRow();
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

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Project);
        
        return $Result;
    }
    
    //update previous project
    public function updateProject($Project){
        $SQL="UPDATE pms_project SET pms_project.thumbnail='".$Project->getProjectThumbnail()."', pms_project.title='".$Project->getProjectTitle()."',pms_project.description='".$Project->getProjectDescription()."',
        pms_project.language='".$Project->getProjectLanguage()."',pms_project.year_id='".$Project->getProjectYearId()."',
        pms_project.term_id='".$Project->getProjectTermId()."',pms_project.course_id='".$Project->getProjectCourseId()."',
        pms_project.discipline_id='".$Project->getProjectDisciplineId()."',pms_project.teacher_id='".$Project->getProjectTeacherId()."',
        pms_project.updated_at=CURRENT_TIMESTAMP WHERE pms_project.id='".$Project->getProjectId()."'";

        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);
        
        return $Result;
    }
    
    //delete specific project
    public function deleteProject($Project){
        $SQL="DELETE FROM pms_project WHERE pms_project.id='".$Project->getProjectId()."'";
        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);
        
        return $Result;
    }
    
}
?>
