var config = {
    type: Phaser.AUTO,
    width: 1200,
    height: 600,
    parent: 'game_div',
    physics: {
        default: 'arcade',
        arcade: {
            gravity: {y: 300},
            debug: false
        }
    },
    scene: {
        preload: preload,
        create: create,
        update: update
    }
};

let game = new Phaser.Game(config);
let platforms;
let player;
let enemies;
let score = 0;
let scoreText;
let HP = 100;
let ShiftLock = false;
let pause = false;
let PauseText;
let GameOverText;
let HPText;
let gameOver;
let bombs;

function preload() {
    this.load.image('background', '/static/img/фон-2.jpg');
    this.load.image('platform', '/static/img/platform.png');
    this.load.image('bomb', '/static/img/bomb.png');
    this.load.spritesheet('enemy', '/static/img/спрайт-07.png', {frameWidth: 80, frameHeight: 80});
    this.load.spritesheet('dude', '/static/img/спрайт-09.png', {frameWidth: 100, frameHeight: 100});
}

function create() {
    this.add.image(400, 300, 'background');
    scoreText = this.add.text(16, 16, 'Score: 0', {fontSize: '32px', fill: '#000'});
    HPText = this.add.text(200, 16, 'HP: 100', {fontSize: '32px', fill: '#000'});
    GameOverText = this.add.text(550, 300, '', {fontSize: '32px', fill: 'red'});
    PauseText = this.add.text(550, 320, '', {fontSize: '32px', fill: 'red'});
    platforms = this.physics.add.staticGroup();

    platforms.create(400, 568, 'platform').setScale(2).refreshBody();
    platforms.create(800, 568, 'platform').setScale(2).refreshBody();
    platforms.create(600, 400, 'platform');
    platforms.create(50, 250, 'platform');
    platforms.create(750, 220, 'platform');
    player = this.physics.add.sprite(100, 450, 'dude');

    player.setBounce(0.2);
    player.setCollideWorldBounds(true);

    this.anims.create({
        key: 'left',
        frames: this.anims.generateFrameNumbers('dude', {start: 12, end: 14}),
        frameRate: 10,
        repeat: -1
    });

    this.anims.create({
        key: 'turn_left',
        frames: [{key: 'dude', frame: 0}],
        frameRate: 20
    });
    this.anims.create({
        key: 'turn_right',
        frames: [{key: 'dude', frame: 1}],
        frameRate: 20
    });
    this.anims.create({
        key: 'attack_left',
        frames: this.anims.generateFrameNumbers('dude', {start: 2, end: 4}),
        frameRate: 15,
        repeat: -1
    });
    this.anims.create({
        key: 'attack_right',
        frames: this.anims.generateFrameNumbers('dude', {start: 9, end: 11}),
        frameRate: 15,
        repeat: -1
    });
    this.anims.create({
        key: 'right',
        frames: this.anims.generateFrameNumbers('dude', {start: 6, end: 8}),
        frameRate: 10,
        repeat: -1
    });
    this.physics.add.collider(player, platforms);
    enemies = this.physics.add.group({
        key: 'enemy',
        repeat: 5,
        setXY: {x: 50, y: 0, stepX: 200}
    });

    enemies.children.iterate(function (child) {

        child.setBounceY(0.1);

    });
    this.physics.add.collider(enemies, platforms);
    this.physics.add.overlap(player, enemies, hitEnemy, null, this);

    bombs = this.physics.add.group();
    this.physics.add.collider(bombs, platforms);
    this.physics.add.collider(player, bombs, hitBomb, null, this);


}

let last_tap = 0;

function update() {
    let cursors = this.input.keyboard.createCursorKeys();
    if (cursors.left.isDown) { // 0
        player.setVelocityX(-160);
        last_tap = 0;
        player.anims.play('left', true);
    } else if (cursors.right.isDown) { // 1
        player.setVelocityX(160);
        last_tap = 1;
        player.anims.play('right', true);
    } else if (cursors.space.isDown) {
        if (last_tap == 0) {
            player.anims.play('attack_left', true);
        } else {
            player.anims.play('attack_right', true);
        }
    } else {
        player.setVelocityX(0);
        if (last_tap == 0) {
            player.anims.play('turn_left');
        } else {
            player.anims.play('turn_right');
        }
    }
    if (cursors.up.isDown && player.body.touching.down) {
        player.setVelocityY(-330);
    }
    if (cursors.shift.isUp) {
        ShiftLock = false;
    }
    if (!ShiftLock) {
        if (cursors.shift.isDown) {
            if (pause) {
                pause = false;
                this.physics.resume();
                PauseText.setText('');
            } else {
                pause = true;
                this.physics.pause();
                PauseText.setText('Pause');
            }
            ShiftLock = true;
        }
    }

    if (HP <= 0) {
        this.physics.pause();
        player.setTint(0xff0000);
        player.anims.play('turn');
        gameOver = true;
        GameOverText.setText('YOU DEAD');
    }
       document.getElementById('score').value = score;
    if (enemies.countActive(true) == 0) {
        SpawnEnemy();
    }
}

function hitEnemy(player, enemy) {
    let cursors = this.input.keyboard.createCursorKeys();
    if (cursors.space.isDown) {
        enemy.disableBody(true, true);
        score += 1;
        scoreText.setText('Score: ' + score);
    } else {
        HP -= 0.5;
        HPText.setText('HP: ' + HP);
    }
}

function SpawnEnemy() {

    enemies.children.iterate(function (child) {
        child.enableBody(true, child.x, 0, true, true);
    });

    var x = (player.x < 400) ? Phaser.Math.Between(400, 800) : Phaser.Math.Between(0, 400);

    var bomb = bombs.create(x, 16, 'bomb');
    bomb.setBounce(1);
    bomb.setCollideWorldBounds(true);
    bomb.setVelocity(Phaser.Math.Between(-200, 200), 20);

}

function hitBomb(player, bomb) {
    this.physics.pause();
    player.setTint(0xff0000);
    player.anims.play('turn');
    gameOver = true;
    GameOverText.setText('YOU DEAD');
}
