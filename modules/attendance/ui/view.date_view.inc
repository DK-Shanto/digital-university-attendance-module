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
$course_no=$Course->getCourseNo();
$course_name = $Course->getTitle();
$course_session = $Session->getName();
$course_year = $Year->getName();
$course_term = $Term->getName();
?>	

<div class="panel panel-deafault">
	<div class="panel-body">
		
		<form action="" method="post">
			<table class="table table-striped">
				<tr>
					<th width="30%">Serial</th>
					<th width="50%">Attendance Date</th>
					<th width="20%">Action</th>
				</tr>
				<?php
					$get_date=$_CourseStudentRegistrationBAO->getDateList($course_name,$course_session); 
					if($get_date){
					
						for($i=1;$value=$get_date->fetch_assoc();$i++){

				?>

				<tr>
					<td><?php echo $i; ?></td>
					<td><?php echo $value['att_date']; ?></td>
					<td>
						<a href="student_view.php?dt=<?php echo $value['att_date']; ?> &course_name=<?php echo $course_name;?> &course_session=<?php echo $course_session;?> ">View</a>
					</td>
				</tr>
				<?php } } ?> 
			</table>
		</form>
	</div>
</div>
