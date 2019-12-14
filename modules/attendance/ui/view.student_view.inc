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
<?php
//$dt=$_GET['dt'];
$course_name = $_GET['course_name'];
$course_session = $_GET['course_session'];
?>


 <?php
	$dt=$_GET['dt'];
	//$course_name = $_GET['course_name'];
	//$course_session = $_GET['course_session'];
	if($_SERVER['REQUEST_METHOD']=='POST'){
		$attend=$_POST['attend'];
		$att_update=$_CourseStudentRegistrationBAO->updateAttendance($dt,$attend,$course_name,$course_session);
	}
?>

<?php
	if(isset($att_update)){
		echo $att_update;
	}
?>


<div class="panel panel-deafault">
	<div class="panel-body">
		<div class="well text-center" style="font-size:20px">
			<strong>Date: </strong><?php echo $dt;?>
		</div>
			<table class="table table-striped">
				<form action="" method="post">
				<tr>
					<th width="25%">Serial</th>
					<th width="25%">Student ID</th>
					<!--<th width="25%">Course Name</th> -->
					<!--<th width="25%">Session</th> -->
					<th width="25%">Attendance</th>
				</tr>
				<?php
					$get_student=$_CourseStudentRegistrationBAO->getAllData($dt,$course_name,$course_session); 
					if($get_student){
					
						for($i=1;$value=$get_student->fetch_assoc();$i++){

				?>
				<tr>
					<td><?php echo $i; ?></td>
					<!--<td><?php echo $value['name']; ?></td>-->
					<td><?php echo $value['roll']; ?></td>
					<!--<td><?php echo $value['course_name']?></td> 
					<td><?php echo $value['session']?></td> -->
					<td>
						<input type="radio" name="attend[<?php echo $value['roll']; ?>]" value="present" <?php if($value['attend']=="present") {echo "checked"; } ?> required="">P
						<input type="radio" name="attend[<?php echo $value['roll']; ?>]" value="absent" <?php if($value['attend']=="absent") {echo "checked"; } ?> required="">A
					</td>
				</tr>
				<?php } } ?>
				<tr>
				<td colspan="4">	
					<button type="submit" name="submit">Update</button>
				</td>
			</tr>
				
		</form>
	 </table>
	</div>
	</div>