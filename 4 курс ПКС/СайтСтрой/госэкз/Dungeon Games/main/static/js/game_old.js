let game_old = new Phaser.Game(1280,720, Phaser.AUTO, 'game_div');
let game_state = {};
let timer = 0;
let i = 60;
let Score = 0;
let timer_spawn = 0;
let collGrPers;
let collGrFood;
game_state.main = function() { };
game_state.main.prototype = {

    preload: function() {
        // загрузка всей необходимой статики
         //this.game.stage.backgroundColor = '#39cf20';
         this.game.load.image('backGround', '/static/img/Фон.png');
         this.game.load.image('hero', '/static/img/Тимон.png');
         this.game.load.image('PRhero', '/static/img/ПРГТимон.png');
         this.game.load.image('Lhero', '/static/img/ЛТимон.png');
         this.game.load.image('Rhero', '/static/img/ПТимон.png');
         this.game.load.image('enemy', '/static/img/Food.png')

    },
    create: function() {
        // настройка игры; вызывается сразу после preload
        this.game.add.image(0,0, 'backGround');
        this.game.physics.startSystem(Phaser.Physics.P2JS);
        this.game.world.setBounds(0,0,1280,720);
        this.game.physics.p2.gravity.y = 1200;
        this.game.physics.p2.setBoundsToWorld(true,true,false,true,false);
        this.hero = this.game.add.sprite(10, 500, 'hero');
        this.hero.height = 200;
        this.hero.width = 100;
        let space_key = this.game.input.keyboard.addKey(Phaser.Keyboard.SPACEBAR);
        space_key.onDown.add(this.jump, this);
        let A_key = this.game.input.keyboard.addKey(Phaser.Keyboard.A);
        A_key.onDown.add(this.left, this);
        let D_key = this.game.input.keyboard.addKey(Phaser.Keyboard.D);
        D_key.onDown.add(this.rigth, this);
        this.hero.angle.toFixed(0);
        this.game.physics.p2.setImpactEvents(true);
        collGrFood = this.game.physics.p2.createCollisionGroup();
        collGrPers = this.game.physics.p2.createCollisionGroup();
        this.game.physics.enable([this.hero], Phaser.Physics.P2JS);
        this.hero.body.setCollisionGroup(collGrPers);
        this.hero.body.collides(collGrFood, this.eat, this);
        this.game.physics.p2.updateBoundsCollisionGroup();

        },
    update: function() {

        if(i>0)
            i--;
        else{
            i = 60;
            timer++;
        }
        if(timer_spawn <240){
            timer_spawn++;
        }else{
            timer_spawn = 0;
            this.enemy = this.game.add.sprite(Phaser.Math.random(50,1280), 10, 'enemy');
            this.enemy.height = 50;
            this.enemy.width = 100;
            game_old.physics.enable([this.enemy], Phaser.Physics.P2JS);
            this.enemy.body.setCollisionGroup(collGrFood);
            this.enemy.body.collides([collGrFood,collGrPers]);
            this.game.physics.p2.updateBoundsCollisionGroup();

        }


        document.getElementById('Timer').innerText='Timer: '+timer;
        document.getElementById('Score').innerText='Score: '+Score;
        if (this.hero.inWorld == false)
            this.restart_game();
    },
    jump: function() {
    // добавляем вертикальную скорость птице
    this.hero.body.velocity.y = -250;
    this.hero.loadTexture('PRhero',0);
},
    eat: function() {
    // добавляем вертикальную скорость птице
    Score+=50;
    this.enemy.destroy();
},
    left: function() {
    // добавляем вертикальную скорость птице
    this.hero.body.velocity.x = -250;
    this.hero.loadTexture('Lhero',0);
},
    rigth: function() {
    // добавляем вертикальную скорость птице
    this.hero.body.velocity.x = +250;
    this.hero.loadTexture('Rhero',0);

},
    restart_game: function() {
    // запускаем состояние "main", которое перезапускает игру
    this.game.state.start('main');
    timer = 0;
    i = 60;

},
    checkCollision: function (sp1, sp2) {
    let boundsA = sp1.getBounds();
    let boundsB = sp2.getBounds();

    return Phaser.Rectangle.intersects(boundsA, boundsB);
    },
};
game_old.state.add('main', game_state.main);
game_old.state.start('main');
