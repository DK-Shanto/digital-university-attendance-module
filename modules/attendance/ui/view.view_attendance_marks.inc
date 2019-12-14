<?php

include_once COMMON.'class.common.course.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.inc';
include_once 'blade/view.view_attendance_marks.blade.inc';
include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.coursebao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_student_registrationbao.inc';
include_once MODULES_REGISTRATION.'bao/class.registration_sessionbao.inc';
include_once MODULES_REGISTRATION.'bao/class.yearbao.inc';
include_once MODULES_REGISTRATION.'bao/class.termbao.inc';
include_once MODULES_USER.'bao/class.userbao.inc';//depenency with modules
include_once MODULES_RESULT.'bao/class.marks_entrybao.inc';//depenency with modules

?>




<div class="panel  panel-default">
<div class="panel-heading"><strong> Attendance Marks </strong></div>
<div class="panel-body">
	<div id="form">
		<form method="post" name="form1" class="form-horizontal">

			<div class="form-group">
          	<label class="control-label col-sm-4" for="CourseID">Course Name:</label>
			 	<div class="col-sm-6">	
							<?php
                                $Result = $_CourseTeacherBAO->getAllOfMyCourses($CourseTeacher);
							if ($Result->getIsSuccess())
							{
								$CourseTeachers = $Result->getResultObject();							}
							?>
							<select name="CourseID" class="form-control" style="width:170px">
								<?php
								for ($i = 0; $i<sizeof($CourseTeachers); $i++){
									$CourseTeacher = $CourseTeachers[$i];

									if (isset($_POST['CourseID'])){

										if ($_POST['CourseID'] == $CourseTeacher->getCourse()->getCourseNo()){
											?>
											<option selected value = "<?php echo $CourseTeacher->getCourse()->getID();?>" > <?php echo $CourseTeacher->getCourse()->getTitle();?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $CourseTeacher->getCourse()->getID();?>" > <?php echo $CourseTeacher->getCourse()->getTitle(); ?> 
											</option>
											<?php
										}
									}	
									else {

											?>
											<option value="<?php echo $CourseTeacher->getCourse()->getID();?>" > <?php echo $CourseTeacher->getCourse()->getTitle();?> 
											</option>
											<?php
									}	
								
								}
								?>	
							</select>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="session">Session:</label>
              	<div class="col-sm-6">	
							<?php
							$Result = $_RegistrationSessionBAO->getAllRegistrationSessions();
							if ($Result->getIsSuccess())
								$SessionList = $Result->getResultObject();					
							?>
							<select name="session" class="form-control" style="width:170px">
								<?php
								for ($i = 0; $i<sizeof($SessionList); $i++){
									$Session = $SessionList[$i];
			
									if (isset($_POST['session'])){

										if ($_POST['session'] == $Session->getID() ){
											?>
											<option selected value = "<?php echo $Session->getID();?>" > <?php echo $Session->getName();?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $Session->getID();?>" > <?php echo $Session->getName(); ?> 
											</option>
											<?php
										}
									}	
									else {

											?>
											<option value="<?php echo $Session->getID();?>" > <?php echo $Session->getName(); ?> 
											</option>
											<?php
									}	
								
								}
								?>	
							</select>
				</div>
			</div>
			<div class="form-group">
              	<label class="control-label col-sm-4" for="year">Year:</label>
              	<div class="col-sm-6">	

				<?php
						$Result = $_YearBAO->getAllYears();
						if ($Result->getIsSuccess())
							$YearList = $Result->getResultObject();					
						?>
							<select name="year" class="form-control" style="width:170px">
								<?php
								for ($i = 0; $i<sizeof($YearList); $i++){
									$Year = $YearList[$i];

									if (isset($_POST['year'])){
										
										if ($_POST['year'] == $Year->getID() ){
											?>
											<option selected value = "<?php echo $Year->getID();?>" > <?php echo $Year->getName();?> 
											</option>
											<?php
										}
										else {

										?>
										<option value="<?php echo $Year->getID();?>" > <?php echo $Year->getName(); ?> 
										</option>
										<?php
										}
									}	
									else {

										?>
										<option value="<?php echo $Year->getID();?>" > <?php echo $Year->getName(); ?> 
										</option>
										<?php
									}	
									
								}
								?>	
							</select>
				</div>
			</div>	
				
			<div class="form-group">
              	<label class="control-label col-sm-4" for="term">Term:</label>
              	<div class="col-sm-6">
				<?php
						$Result = $_TermBAO->getAllTerms();
						if ($Result->getIsSuccess())
							$TermList = $Result->getResultObject();					
						?>

							<select name="term" class="form-control" style="width:170px">
								<?php
								for ($i = 0; $i<sizeof($TermList); $i++){
									$Term = $TermList[$i];

									if (isset($_POST['term'])){
										
										if ($_POST['term'] == $Term->getID() ){
											?>
											<option selected value = "<?php echo $Term->getID();?>" > <?php echo $Term->getName();?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $Term->getID();?>" > <?php echo $Term->getName(); ?> 
											</option>
											<?php
										}
									}	
									else {

											?>
											<option value="<?php echo $Term->getID();?>" > <?php echo $Term->getName(); ?> 
											</option>
											<?php
									}	
								
								}
								?>	
							</select>
				</div>
			</div>

			<div class="form-group">
              	<div class="col-sm-6">	
						<button type="submit" name="load_marks">Load Marks</button>
				</div>

			</div>
		</form>

<div>
<div><strong>Currently Registered Students</strong></div>
<div class="panel-body"> 
<table class="table table-bordered">
	<tr>
		<th width="25%">     University ID(Student ID)</th>
		<th width="25%">     Marks(OUT OF 10)</th>
	</tr>

	<?php
    
   //echo sizeof($StudentIDList);
   $Session ='2016-2017';
	//echo $Session_name;



	if(isset($Result_Course_Students))
	{
		//$StudentIDList=null;
		$CourseStudentRegistrations = $Result_Course_Students->getResultObject();
		$x= count($CourseStudentRegistrations);
		//echo $x;
		if($x!=0&&$x!=1)
		{

		for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
			$CourseStudentRegistration = $CourseStudentRegistrations[$i];
			$StudentID = $CourseStudentRegistration->getStudent()->getUniversityID();
			$final = $_CourseStudentRegistrationBAO->calculateResult($StudentID,$Session);
			?>
		<tr>
		 <td><?php echo $StudentID;?></td>
		 <td><?php echo $final;?></td>
		</tr>
		<?php
		}
	}
	else
	{
		echo 'No Students to Display';
	}
	}
	
	?>
</table>
</div>
</div>
</div>