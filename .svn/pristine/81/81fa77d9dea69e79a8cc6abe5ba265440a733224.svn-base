<?php
include_once 'blade/view.searchThesis.blade.inc';
include_once COMMON.'class.common.inc';
?>

<link rel="stylesheet" href="./resources/css/sidebarStyle.css">

<div class="container">

    <!--Sidebar-->
    <div class="col-md-3">
      <nav class="navbar navbar-default sidebar" role="navigation">
        <div class="container-fluid">
            <div class="navbar-header mySideNav">
                <span><strong style="font-size: large"><img src="./resources/img/filter.png" alt="Icon" height = "40" weight ="40" class="myImg">Filter</strong></span>
                <!--Responsive-->
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-sidebar-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
            </div>
            <div class="collapse navbar-collapse" id="bs-sidebar-navbar-collapse-1">

                <!--Title-->
                <ul class="nav navbar-nav">
                    <li class="mySideNavList" >&nbsp Title<span class="pull-right"><input type="checkbox" name="cbtitle" id="cbtitle"<?php
                            if (isset($_POST['search'])&&isset($_POST['title'])&&!empty($_POST['title'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li><br>

                    <!--Year-->
                    <li class="mySideNavList" >&nbsp Year<span class="pull-right"><input type="checkbox" name="cbyear" id="cbyear"<?php
                            if (isset($_POST['search'])&&isset($_POST['year_id'])&&!empty($_POST['year_id'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li>

                    <!--Term-->
                    <li class="mySideNavList" >&nbsp Term<span class="pull-right"><input type="checkbox" name="cbterm" id="cbterm"<?php
                            if (isset($_POST['search'])&&isset($_POST['term_id'])&&!empty($_POST['term_id'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li>

                    <!--Course-->
                    <li class="mySideNavList" >&nbsp Course<span class="pull-right"><input type="checkbox" name="cbcourse" id="cbcourse"<?php
                            if (isset($_POST['search'])&&isset($_POST['course_id'])&&!empty($_POST['course_id'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li>

                    <!--Discipline-->
                    <li class="mySideNavList" >&nbsp Discipline<span class="pull-right"><input type="checkbox" name="cbdiscipline" id="cbdiscipline"<?php
                            if (isset($_POST['search'])&&isset($_POST['discipline_id'])&&!empty($_POST['discipline_id'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li>

                    <!--Teacher-->
                    <li class="mySideNavList" >&nbsp Supervisor<span class="pull-right"><input type="checkbox" name="cbteacher" id="cbteacher"<?php
                            if (isset($_POST['search'])&&isset($_POST['teacher_id'])&&!empty($_POST['teacher_id'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li>

                    <!--Member-->
                    <li class="mySideNavList" >&nbsp Member<span class="pull-right"><input type="checkbox" name="cbmember" id="cbmember"<?php
                            if (isset($_POST['search'])&&isset($_POST['member_id'])&&!empty($_POST['member_id'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li>

                    <!--CreatedAt-->
                    <li class="mySideNavList" >&nbsp Date<span class="pull-right"><input type="checkbox" name="cbdate" id="cbdate"<?php
                            if (isset($_POST['search'])&&isset($_POST['created_at'])&&!empty($_POST['created_at'])){
                                ?>
                                checked="checked"
                                <?php
                            }
                            ?> onchange="cbFunction();"></span></li>
                </ul>
            </div>
        </div>
    </nav>
    </div>

    <!--Search Div-->
    <div class="col-md-9">
        <div class="panel panel-default myPanel">

            <div class="panel-heading myHeading">
                <strong><img src="./resources/img/searchProject.png" alt="Icon" height="40" weight ="40" class="myImg">&nbsp;Search Thesis</strong>
            </div>

            <div class="panel-body form-horizontal">

                <!--Search Form-->
                <form method="post" class="form-horizontal">

                    <!--Title-->
                    <div id="divtitle" class="form-group" hidden >
                        <label for="title" class="control-label col-md-3">Title :</label>
                        <div class="col-md-7">
                            <input type="text" name="title" id="title" class="form-control" placeholder="Thesis Title" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['title'])) echo $_POST['title'];
                            ?>" required>
                        </div>
                    </div>

                    <!--Year-->
                    <div id="divyear" class="form-group" hidden>
                        <label for="year_id" class="control-label col-md-3">Year :</label>
                        <div class="col-md-7">
                            <select name="year_id" id="year_id" class="form-control" required>
                                <option value="" selected="selected" disabled>Select Year</option>
                                <?php
                                $Result=$_ThesisBao->getAllYears();
                                if ($Result->getIsSuccess()){
                                    $YearList=$Result->getResultObject();
                                    foreach ($YearList as $year) {
                                        ?>
                                        <option value="<?php echo $year->getID();?>"<?php
                                        if (isset($_POST['search'])&&!empty($_POST['year_id'])&&$year->getID()==$_POST['year_id']) echo 'selected="selected"';
                                        ?>><?php echo $year->getName();?></option>
                                        <?php
                                    }
                                }else{
                                    echo $Result->getResultObject();
                                }

                                ?>
                            </select>
                        </div>
                    </div>

                    <!--Term-->
                    <div id="divterm" class="form-group" hidden>
                        <label for="term_id" class="control-label col-md-3">Term :</label>
                        <div class="col-md-7">
                            <select name="term_id" id="term_id" class="form-control" required>
                                <option value="" selected="selected" disabled>Select Term</option>
                                <?php
                                $Result=$_ThesisBao->getAllTerms();
                                if ($Result->getIsSuccess()){
                                    $TermList=$Result->getResultObject();
                                    foreach ($TermList as $term) {
                                        ?>
                                        <option value="<?php echo $term->getID();?>"<?php
                                        if (isset($_POST['search'])&&!empty($_POST['term_id'])&&$term->getID()==$_POST['term_id']) echo 'selected="selected"';
                                        ?>><?php echo $term->getName();?></option>
                                        <?php
                                    }
                                }else{
                                    echo $Result->getResultObject();
                                }
                                ?>
                            </select>
                        </div>
                    </div>

                    <!--Course-->
                    <div id="divcourse" class="form-group" hidden>
                        <label for="course_id" class="control-label col-md-3">Course :</label>
                        <div class="col-md-7">
                            <select name="course_id" id="course_id" class="form-control" required>
                                <option value="" selected="selected" disabled>Select Course</option>
                                <?php
                                $Result=$_ThesisBao->getAllCourses();
                                if ($Result->getIsSuccess()){
                                    $CourseList=$Result->getResultObject();
                                    foreach ($CourseList as $course) {
                                        ?>
                                        <option value="<?php echo $course->getID();?>"<?php
                                        if (isset($_POST['search'])&&!empty($_POST['course_id'])&&$course->getID()==$_POST['course_id']) echo 'selected="selected"';
                                        ?>><?php echo $course->getTitle();?></option>
                                        <?php
                                    }
                                }else{
                                    echo $Result->getResultObject();
                                }
                                ?>
                            </select>
                        </div>
                    </div>

                    <!--Discipline-->
                    <div id="divdiscipline" class="form-group" hidden>
                        <label for="discipline_id" class="control-label col-md-3">Discipline :</label>
                        <div class="col-md-7">
                            <select name="discipline_id" id="discipline_id" class="form-control" required>
                                <option value="" selected="selected" disabled>Select Discipline</option>
                                <?php
                                $Result=$_ThesisBao->getAllDisciplines();
                                if ($Result->getIsSuccess()){
                                    $DisciplineList=$Result->getResultObject();
                                    foreach ($DisciplineList as $discipline) {
                                        ?>
                                        <option value="<?php echo $discipline->getID();?>"<?php
                                        if (isset($_POST['search'])&&!empty($_POST['discipline_id'])&&$discipline->getID()==$_POST['discipline_id']) echo 'selected="selected"';
                                        ?>><?php echo $discipline->getName();?></option>
                                        <?php
                                    }
                                }else{
                                    echo $Result->getResultObject();
                                }
                                ?>
                            </select>
                        </div>
                    </div>

                    <!--Teacher-->
                    <div id="divteacher" class="form-group" hidden>
                        <label for="teacher_id" class="control-label col-md-3">Teacher:</label>
                        <div class="col-md-7">
                            <select name="teacher_id" id="teacher_id" class="form-control" required>
                                <option value="" selected="selected" disabled>Select Teacher</option>
                                <?php
                                $Result=$_ThesisBao->getAllTeachers();
                                if ($Result->getIsSuccess()){
                                    $TeacherList=$Result->getResultObject();
                                    foreach ($TeacherList as $teacher) {
                                        ?>
                                        <option value="<?php echo $teacher->getID();?>"<?php
                                        if (isset($_POST['search'])&&!empty($_POST['teacher_id'])&&$teacher->getID()==$_POST['teacher_id']) echo 'selected="selected"';
                                        ?>><?php echo $teacher->getFirstName().' '.$teacher->getLastName();?></option>
                                        <?php
                                    }
                                }else{
                                    echo $Result->getResultObject();
                                }
                                ?>
                            </select>
                        </div>
                    </div>

                    <!--Member-->
                    <div id="divmember" class="form-group" hidden>
                        <label for="member_id" class="control-label col-md-3">Member :</label>
                        <div class="col-md-7">
                            <select name="member_id" id="member_id" class="form-control" required>
                                <option value="" selected="selected" disabled>Select Member</option>
                                <?php
                                $Result=$_SearchThesisBao->getAllStudents();
                                if ($Result->getIsSuccess()){
                                    $StudentList=$Result->getResultObject();
                                    foreach ($StudentList as $student) {
                                        ?>
                                        <option value="<?php echo $student->getID();?>"<?php
                                        if (isset($_POST['search'])&&!empty($_POST['member_id'])&&$student->getID()==$_POST['member_id']) echo 'selected="selected"';
                                        ?>><?php echo $student->getFirstName().' '.$student->getLastName();?></option>
                                        <?php
                                    }
                                }else{
                                    echo $Result->getResultObject();
                                }
                                ?>
                            </select>
                        </div>
                    </div>

                    <!--CreatedAt-->
                    <div id="divcreated_at" class="form-group" hidden>
                        <label for="created_at" class="control-label col-md-3">Date :</label>
                        <div class="col-md-7">
                            <input type="date" name="created_at" id="created_at" class="form-control" value="<?php
                            if (isset($_POST['search'])&&!empty($_POST['created_at'])) echo $_POST['created_at'];
                            ?>" required>
                        </div>
                    </div>

                    <br>

                    <!--Search Button-->
                    <div class="form-group">
                        <input type="submit" name="search" id="search" class="btn btn-primary col-md-2 col-md-offset-5" value="Search">
                    </div>
                </form>

            </div>
        </div>
    </div>
</div>

<!--Display Search Results-->
<?php
if (isset($_POST['search'])&&(!empty($_POST['title'])||!empty($_POST['language'])||!empty($_POST['year_id'])||!empty($_POST['term_id'])
    ||!empty($_POST['course_id'])||!empty($_POST['discipline_id'])||!empty($_POST['teacher_id'])||!empty($_POST['member_id'])||!empty($_POST['created_at']))){
    ?>
    <div class="col-md-12">
        <hr>
    </div>
    <div class="col-md-12">
    <div class="panel panel-table">
        <table class="table table-striped table-bordered table-responsive">
            <!--Header Row-->
            <tr>
                <th>Title</th>
                <th>Description</th>
                <th>Report</th>
                <th>Year</th>
                <th>Term</th>
                <th>Course</th>
                <th>Discipline</th>
                <th>Created At</th>
                <th>Updated At</th>
            </tr>

            <!--Table Cells-->
            <?php
            $Result=$_SearchThesisBao->getSearchedThesis();
            if($Result->getIsSuccess()){
                $ThesisList=$Result->getResultObject();

                foreach ($ThesisList as $thesis) {
                    ?>
                    <tr>
                        <td><a href="thesis_member.php?id=<?php echo $thesis->getThesisId();?>"><img src="<?php echo $thesis->getThesisThumbnail();?>" alt="Icon" height="40" weight = "40" class="table-img"><?php
                                echo ' '.$thesis->getThesisTitle(); ?></a></td>

                        <td><?php if(strlen($thesis->getThesisDescription())>50){
                                echo substr($thesis->getThesisDescription(),0,50).'...';
                            }else{
                                echo $thesis->getThesisDescription();
                            }  ?></td>

                        <td class="table-cell"><a href="<?php echo $thesis->getThesisPDFLink(); ?>" style="text-decoration: none"><?php
                                if(strlen($thesis->getThesisTitle())>40){
                                    echo substr($thesis->getThesisTitle(),0,40).'...'.'.pdf' ;
                                }else{
                                    echo $thesis->getThesisTitle().'.pdf';
                                } ?></a></td>

                        <td class="table-cell"><?php echo $Result=$_ThesisBao->getYear($thesis->getThesisYearId())->getResultObject()->getName();?></td>

                        <td class="table-cell"><?php echo $Result=$_ThesisBao->getTerm($thesis->getThesisTermId())->getResultObject()->getName();?></td>

                        <td><?php echo $Result=$_ThesisBao->getCourse($thesis->getThesisCourseId())->getResultObject()->getTitle();?></td>

                        <td><?php echo $Result=$_ThesisBao->getDiscipline($thesis->getThesisDisciplineId())->getResultObject()->getName();?></td>

                        <td class="table-cell"><?php echo $thesis->getThesisCreatedAt();?></td>

                        <td class="table-cell"><?php echo $thesis->getThesisUpdatedAt();?></td>

                    </tr>
                    <?php
                }
            }
            ?>
        </table>
    </div>
    </div>
    <?php
}
?>

<!--Script for loading searching options-->
<script>
    //Load on postback
    $(document).ready(function() {
        cbFunction();
    });

    function cbFunction() {
        //Title CB
        if($('#cbtitle').prop('checked')){
            $('#divtitle').show();
            $('#title').prop('required',true);
        }else {
            $('#divtitle').hide();
            $('#title').prop('required',false);
            $('#title').val(null);
        }

        //Year CB
        if($('#cbyear').prop('checked')){
            $('#divyear').show();
            $('#year_id').prop('required',true);
        }else{
            $('#divyear').hide();
            $('#year_id').prop('required',false);
            $('#year_id').val(null);
        }

        //Term CB
        if($('#cbterm').prop('checked')){
            $('#divterm').show();
            $('#term_id').prop('required',true);
        }else{
            $('#divterm').hide();
            $('#term_id').prop('required',false);
            $('#term_id').val(null);
        }

        //Course CB
        if($('#cbcourse').prop('checked')){
            $('#divcourse').show();
            $('#course_id').prop('required',true);
        }else{
            $('#divcourse').hide();
            $('#course_id').prop('required',false);
            $('#course_id').val(null);
        }

        //Discipline CB
        if($('#cbdiscipline').prop('checked')){
            $('#divdiscipline').show();
            $('#discipline_id').prop('required',true);
        }else{
            $('#divdiscipline').hide();
            $('#discipline_id').prop('required',false);
            $('#discipline_id').val(null);
        }

        //Teacher CB
        if($('#cbteacher').prop('checked')){
            $('#divteacher').show();
            $('#teacher_id').prop('required',true);
        }else{
            $('#divteacher').hide();
            $('#teacher_id').prop('required',false);
            $('#teacher_id').val(null);
        }

        //Member CB
        if($('#cbmember').prop('checked')){
            $('#divmember').show();
            $('#member_id').prop('required',true);
        }else{
            $('#divmember').hide();
            $('#member_id').prop('required',false);
            $('#member_id').val(null);
        }

        //Date CB
        if($('#cbdate').prop('checked')){
            $('#divcreated_at').show();
            $('#created_at').prop('required',true);
        }else{
            $('#divcreated_at').hide();
            $('#created_at').prop('required',false);
            $('#created_at').val(null);
        }
    }
</script>