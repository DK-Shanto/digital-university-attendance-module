<?php
include_once COMMON.'class.common.course.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.inc';
include_once 'blade/view.student_registered.blade.inc';
include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.coursebao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_student_registrationbao.inc';
include_once MODULES_REGISTRATION.'bao/class.registration_sessionbao.inc';
include_once MODULES_REGISTRATION.'bao/class.yearbao.inc';
include_once MODULES_REGISTRATION.'bao/class.termbao.inc';
include_once MODULES_USER.'bao/class.userbao.inc';//depenency with modules
include_once MODULES_RESULT.'bao/class.marks_entrybao.inc';//depenency with modules

?>
<div>
	   <link rel="stylesheet" href="//code.jquery.com/ui/1.12.1/themes/base/jquery-ui.css">
  <link rel="stylesheet" href="/resources/demos/style.css">
  <script src="https://code.jquery.com/jquery-1.12.4.js"></script>
  <script src="https://code.jquery.com/ui/1.12.1/jquery-ui.js"></script>
       <script>
  $( function() {
    $( "#datepicker" ).datepicker();
    //onSelect: function() { 
        //var dateObject = $(this).datepicker('getDate'); 
    
  } );
  </script>
</div>

<?php
$cur_date=date("Y-m-d");
$course_no=$Course->getCourseNo();
$course_name = $Course->getTitle();
$course_session = $Session->getName();
$course_year = $Year->getName();
$course_term = $Term->getName();
?>	

<?php

$cur_date=date("Y-m-d");
    if($_SERVER['REQUEST_METHOD']=='POST'){
        $attend=$_POST['attend'];
        $insertattend=$_CourseStudentRegistrationBAO->insertAttendance($cur_date,$attend,$course_name,$course_session);
    }
?>

<?php
  if(isset($insertattend)){
        echo $insertattend;
    }
?>
<!--

<div class="panel  panel-default">
<div class="panel-heading"><strong>Coursewise Marks Update</strong></div>
<div class="panel-body">
	<div id="form">
		<form method="post" name="form1" class="form-horizontal">

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtCourseNo">Course No:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtCourseNo" class="form-control" 
				value="<?php if(isset($Course)) echo $Course->getCourseNo(); ?>" readonly/>
				<input type="hidden" name="hiddenCourseID" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Course)) echo $Course->getID(); ?>" readonly/>				
			 	</div>
			</div>

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtCourseTitle">Course Title:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtCourseTitle" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Course)) echo $Course->getTitle(); ?>" readonly/>
			 	</div>
			</div>

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtSession">Session:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtSession" class="form-control" 
				value="<?php if(isset($Session)) echo $Session->getName(); ?>" readonly/>
				<input type="hidden" name="hiddenSession" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Session)) echo $Session->getID(); ?>" readonly/>				
			 	</div>
			</div>

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtYear">Year:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtYear" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Year)) echo $Year->getName(); ?>" readonly/>
				<input type="hidden" name="hiddenYear" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Year)) echo $Year->getID(); ?>" readonly/>

			 	</div>
			</div>

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtTerm">Term:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtTerm" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Term)) echo $Term->getName(); ?>" readonly/>
				<input type="hidden" name="hiddenTerm" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Term)) echo $Term->getID(); ?>" readonly/>

			 	</div>
			</div>	
			-->			
     <!--
	        <div class="form-group">        
              	<div class="col-sm-4">	
						<button type="submit" name="save_marks">Save</button>
	
				</div>
              	<div class="col-sm-4">	

						<button type="submit" name="notify_marks">Notify</button>
	
				</div>
              	<div class="col-sm-4">	

						<button type="submit" name="delete_marks" onclick="return confirm('Sure to delete! All the test marks from the database for this registration will be deleted?'); ">Delete</button>
	
				</div>
             		
			</div> 
	   -->
	<!--</div>


</div> -->
<div class="panel panel-deafault">
	<div class="panel-body">
<div><strong>Currently Registered Students</strong></div>

  <!--<div align="center" style="font-size:20px"><strong>Date: </strong><?php echo $cur_date;?>-->

    <!--<div class="panel-body">  -->
		<div class="well text-center" style="font-size:20px">
			<!--<strong>Date: </strong><?php echo $cur_date;?>-->
			<strong>Date: </strong><input type="text" id="datepicker">
		</div> 

	
<table class="table table-bordered">

	<form action="" method="post">
	
		<!--form method="post" name="form2" class="form-horizontal"-->
<?php
	//searching the marks entry in the result list that match student id

   
	function findMarksEntry($MarksEntryList,$StudentID){

		for ($i=0; $i < sizeof($MarksEntryList) ; $i++) { 
			
			$MarksEntry = $MarksEntryList[$i];
			if($MarksEntry->getStudent()==$StudentID)
				return $MarksEntry;
		}

		return null;
	}

  
	

	if(isset($Result_Course_Students) && isset($Result_Course_Teacher)&&isset($Result_Course_Student_Tests))
	{
		$StudentIDList=null;
		$CourseStudentRegistrations = $Result_Course_Students->getResultObject();

		for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
			$CourseStudentRegistration = $CourseStudentRegistrations[$i];
			$StudentIDList[] = $CourseStudentRegistration->getStudent()->getUniversityID();
		}	

	    $MarksEntryList= $Result_Course_Student_Tests->getResultObject(); //all student registered

		$NoOfTests = $Result_Course_Teacher->getNoOfTests();


         

		?>
		<?php
		if ($StudentIDList!=null) {
			?>
			<input type="hidden" name="hidden_all_students" value="<?php echo implode(",", $StudentIDList); ?>" />
		<input type="hidden" name="hidden_no_of_tests" value="<?php echo $NoOfTests; ?>" />
			<?php
		}
		else
		{
			echo "No students to show";
		}
		?>
		<tr>
			<th>Serial NO</th>
			<th>University ID</th>
			<th>Name</th>
			<th>Attendance Sheet</th>

			<!--
		<?php	for ($i=1; $i <= $NoOfTests ; $i++) { 
				echo '<th>Test ('.$i.')</th>';
			}
		?>	
	-->
		</tr>
		<?php 
		for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
			$CourseStudentRegistration = $CourseStudentRegistrations[$i];
			$StudentID = $CourseStudentRegistration->getStudent()->getUniversityID();
			$StudentEmail = $CourseStudentRegistration->getStudent()->getID();
             $StudentName= $CourseStudentRegistration->getStudent()->getFullName(); 
			$MarksEntry = findMarksEntry($MarksEntryList,$StudentID);//marks entry, marks value
			
			//$Quer=$_CourseStudentRegistrationBAO->inserttry($StudentID, $StudentName);

			?>
			<tr>
               <!--
				<td>
				<input type="text" name="<?php echo $StudentID; ?>" 
						value="<?php echo $StudentID; ?>" size="0" readonly/>
				</td>
			-->
			   <td><?php echo $i+1; ?></td>
			  <td><?php echo $StudentID ;?></td>
				<td><?php echo $StudentName ;?> 
				</td>

				<!--<td> <?php if(isset($Session)) echo $Session->getName(); ?></td> -->

               
               <!--change korci -->
				<td>
						<input type="radio" name="attend[<?php echo $StudentID ;?>]" value="present" required="">P
						<input type="radio" name="attend[<?php echo $StudentID ;?>]" value="absent" required="">A 
					</td>

				<!-- change kori -->
				<!--
				<?php	
					$MarksValueList = null;
					if(isset($MarksEntry))
						$MarksValueList = explode(",",$MarksEntry->getMarksValue());

					for ($j=0; $j < $NoOfTests ; $j++) {
						if(isset($MarksValueList)&&isset($MarksValueList[$j])){
							echo '<td><input type="text" name="'.$StudentID.'[\''.($j+1).'\']" 
								  value="'.$MarksValueList[$j].'" size="3"	/></td>';
						}
						else{
							echo '<td><input type="text" name="'.$StudentID.'[\''.($j+1).'\']" 
								  value="X" size="3"	/></td>';

						}		  
					}
				?>	
			-->

			</tr>


			
       <?php

		}

    	
	}
	else{


	echo 'No students to display!';
	}

?>
            <tr>
				<td colspan="4">
					
					<button type="submit" name="submit">Submit</button>
				</td>
			</tr>
            <!--
			<tr>
				<a href="see-attendance.php">View Attendance</a>
			</tr>	
		-->
  

</form>
</table>


</div>


