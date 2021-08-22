<?php
if(isset($_GET['update']))
{
  
    $CourseID = $_DB->secureInput($_GET['course']);

    $TeacherID = $_DB->secureInput($_GET['teacher']);    
 
    $SessionID = $_DB->secureInput($_GET['session']);

    $YearID = $_DB->secureInput($_GET['year']);

    $TermID = $_DB->secureInput($_GET['term']);
  
    //read all registered students to this course

    $Result_Course_Students = $_CourseBAO->searchAllStudents($CourseID,$SessionID,$YearID,$TermID);
    //read the class tests of the students for this course, session, year, term
    if($Result_Course_Students->getIsSuccess())
    {
    $Result_Course_Student_Tests = $_MarksEntryBAO->getCourseStudentTests($CourseID,$SessionID,$YearID,
        $TermID,$Result_Course_Students->getResultObject());


    //read the course teacher row to get the no of tests
    $Result_Course_Teacher = $_MarksEntryBAO->readCourseTeacher($CourseID,$TeacherID,$SessionID,$YearID,$TermID)->getResultObject();

   }

    $Course = new Course();
    $Course->setID($CourseID);
    $Course = $_CourseBAO->readCourse($Course)->getResultObject();


    $Teacher = new User();
    $Teacher->setID($TeacherID);
    $Teacher = $_UserBAO->readUser($Teacher)->getResultObject();


    $Session = new RegistrationSession();
    $Session->setID($SessionID);
    $Session = $_RegistrationSessionBAO->readRegistrationSession($Session)->getResultObject();


    $Year = new Year();
    $Year->setID($YearID);
    $Year=$_YearBAO->readYear($Year)->getResultObject();


    $Term = new Term();
    $Term->setID($TermID);
    $Term=$_TermBAO->readTerm($Term)->getResultObject();

}
?>